#include <iostream>
#include <string>
using namespace std;
int main(){
    string num;
    cin >> num;
    string cur(num);
    int cnt = 0;
    int temp;
    do{
    
    temp = 0;
    for(int i=0;i<cur.length();i++){
        temp += cur[i]-'0';
    }
    cur = cur.back();
    cur.push_back(to_string(temp).back());
    cur = to_string(stoi(cur));
    cnt++;
    }while(num != cur);

    cout<<cnt;
    return 0;
}