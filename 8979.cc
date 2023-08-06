#include <iostream>
using namespace std;

class Olympic{
    int natNum;
    int** medals;
    int target;

    void swap(int idx1,int idx2){
        // cout<<"before: " << medals[idx1] << " " << medals[idx2];
        int* temp;
        temp = medals[idx1];
        medals[idx1] = medals[idx2];
        medals[idx2] = temp;
        // cout<<"after: " << medals[idx1] << " " << medals[idx2];
        return;
    }
    void insertion_sort(){
        //medals[i]를 medals[0]~medals[i-1]들과 비교
        //앞자리일 수록 높은 순위
        for(int i=1;i<natNum;i++){ 
            for(int j=0;j<i;j++){
                // cout<< "i= "<<i<<": "<<medals[i][0]<<" "<< medals[i][1]<<" "<<medals[i][2]<<"\n";
                // cout<< "j= "<<j<<": "<<medals[j][0]<<" "<< medals[j][1]<<" "<<medals[j][2]<<"\n";
                if(medals[i][0]>medals[j][0] || 
                    (medals[i][0]==medals[j][0] && medals[i][1]>medals[j][1]) || 
                    (medals[i][0]==medals[j][0] && medals[i][1]==medals[j][1] && medals[i][2]>medals[j][2])){
                    swap(i,j);
                }
            }
        }
    return;
    }

    int _score(){
        int cnt=1;
        int real=1;
        medals[0][4] = 1;
        for(int i=1;i<natNum;i++){
            cnt++;
            real++;
            if(medals[i][0]==medals[i-1][0] && 
                medals[i][1]==medals[i-1][1] && 
                medals[i][2]==medals[i-1][2]){
                medals[i][4] = --cnt;
            }
            else{
                medals[i][4] = real;
                cnt = real;
            }
            if(medals[i][3] == target) return medals[i][4];
        }
        return 1;
        
    }
    public:

   int score(){
        insertion_sort();
        int result = _score();
        return result;
    }
    void printmedal(){
        for(int i=0;i<natNum;i++){
            for(int j=0;j<5;j++){
                cout<<medals[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    void init(){
        int natIdx,gold, silver, bronze;

        cin >> natNum >> target;
        medals = new int*[natNum];
        
        for(int i=0;i<natNum;i++){
            cin>>natIdx>>gold>>silver>>bronze;
            medals[i] = new int[5];
            medals[i][0] = gold;
            medals[i][1] = silver;
            medals[i][2] = bronze; 
            medals[i][3] = natIdx; //index
            //medals[natIdx][4]: score
        }
        
        return;
    }

};

int main(){
    
    Olympic o;
    o.init();
    cout<<o.score()<<endl;
    o.printmedal();

    return 0;
}