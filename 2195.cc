#include <iostream>
#include <string>
using namespace std;

int main(){
    string org,tar;
    getline(cin,org);
    getline(cin,tar);
    string left_char(tar);

    string temp;
    int cnt = 0;
    while(left_char.empty() == 0){
        int max_len = 0;
        
        for(int i=0;i<org.length();i++){
            int j=0;
            while(left_char[j] == org[i] && i<org.length() && j<left_char.length()){
                i++;
                j++;
            }
            if(max_len < j){
                max_len = j;
            }
        }
        left_char = left_char.erase(0,max_len);
        cnt++;
    }
    cout<<cnt;
    return 0;
}