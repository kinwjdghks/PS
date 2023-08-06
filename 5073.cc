#include <iostream>
#include <string>
using namespace std;


int main(){
    int a,b,c;
    while(1){
        scanf("%d %d %d",&a,&b,&c);
        if(a==0 && b==0 && c==0) break;

        if(a+b<=c || b+c<=a || a+c<=b){
            cout<<"Invalid"<<"\n";
        }
        else if(a==b && a==c) cout<<"Equilateral"<<"\n";
        else if(a==b || a==c || b==c) cout<<"Isosceles"<<"\n";
        else cout<<"Scalence"<<"\n";
    }
    return 0;
}