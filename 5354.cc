#include <iostream>
using namespace std;


void Jbox(int N){
    
    int i=1;
    while(i<=N){
        if(i==1 || i==N){
            for(int j=0;j<N;j++) cout<<"#";
        }
        else{
            cout<<"#";
            for(int j=0;j<N-2;j++) cout<<"J";
            cout<<"#";
        }
        cout<<"\n";
        i++;
    }
    return;
}

int main(){

    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        Jbox(x);
        cout<<"\n";
    }
    return 0;
}