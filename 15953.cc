#include <iostream>
#include <string>
using namespace std;

class prize{
    int first_(int place){
        if(place == 0) return 0;
        else if(1 == place) return 5000000;
        else if(2<=place&& place<=2+1) return 3000000;
        else if(4<=place&& place<=4+2) return 2000000;
        else if(7<=place&& place<=7+3) return 500000;
        else if(11<=place&& place<=11+4) return 300000;
        else if(16<=place&& place<=16+5) return 100000;
        else return 0;
    }
    int second_(int place){
        if(place == 0) return 0;
        else if(1 == place) return (1<<9)*10000;
        else if(2<=place&& place<=2+1) return (1<<8)*10000;
        else if(4<=place&& place<=4+3) return (1<<7)*10000;
        else if(8<=place&& place<=8+7) return (1<<6)*10000;
        else if(16<=place&& place<=16+15) return (1<<5)*10000;
        else return 0;
    }
    public:
    int total(int first,int second){
        return first_(first)+second_(second);
    }

};

int main(){
    int num,first,second;
    prize p;
    cin>>num;
    
    for(int i=0;i<num;i++){
        scanf("%d %d",&first,&second);
        cout<<p.total(first,second)<<"\n";
    }
    return 0;
}