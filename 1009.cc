#include <iostream>
using namespace std;

int power(int a,int n){
    if(n==0) return 1;
    else if(n%2==0){
        return (power(a,n/2)%10)*(power(a,n/2)%10);
    }
    else return a*(power(a,(n-1)/2)%10)*(power(a,(n-1)/2)%10);
}
int main() {
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		int res = power(a%10,b)%10;
        res = res ? res : 10;
		cout<< res <<"\n";
	}
	
	return 0;
}