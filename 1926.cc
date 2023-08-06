#include <iostream>
using namespace std;

class D{
    short** board;
    int size;
    
    public:
    void init(){
        cin>> size;
        board = new short*[size];
        /*init board*/
        for(int i=0;i<size;i++){
            board[i] = new short[size];
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cin>> board[i][j];
            }
        }
        STACK.push(make_tuple(1,0,1));
    }
};
int main(){

    return 0;
}