#include <iostream>
#include <string>
using namespace std;

void convert_num(char* line,int len){
    for(int i=0;i<(len+1)/2;i++){
        line[2*i] -= '0';
    }
    return;
}
void print_line(char* line, int len){
    for(int i=0;i<len;i++){
        if(i%2 == 0) printf("%d",line[i]);
        else printf("%c",line[i]);
    }
    cout<<"\n";
}
int calculate(int len,char* line){
    // cout<<line;
    if(len ==1){
        return line[0];
    }
    else{
        int num;
        
        if(line[1] == '+'){
            num = line[0]+line[2];
        }
        else if(line[1] == '-'){
            num = line[0]-line[2];
        }
        else{
            num = line[0]*line[2];
        }
        
        line[2] = num;
        print_line(line+2,len-2);
        
        return calculate(len-2,line+2);
    }
    
}

int main(){
    int len;
    cin>>len;
    cin.ignore();
    char* line = (char*)malloc(sizeof(char)*(len+1));
    cin.getline(line,len+1);
    convert_num(line,len);
    
    cout<<calculate(len,line);
    delete line;
    return 0;
}