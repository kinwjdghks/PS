#include <iostream>
#include <stack>
#include <tuple>
using namespace std;
class PIPE{
    private:
    int size;
    short** board;
    int cnt;
    stack<tuple<int,int,int> > STACK; //direction(0:세로 1:가로 2:대각선),x,y
    
    void print_stack(){
        while(STACK.size()){
            tuple<int,int,int> a = STACK.top();
            STACK.pop();
            cout<<"STACK: \n";
            cout<<get<0>(a)<<" "<<get<1>(a)<<" "<<get<2>(a)<<"\n";
        }
        cout<<"\n";
    }

    void seek(int d,int x,int y){
        // cout<<"seek: "<<d<<" "<<x<<" "<<y<<"\n";
        if(d==0){ //세로
            if(x+1 <= size-1){
                if(board[x+1][y]==0){
                    STACK.push(make_tuple(0,x+1,y));
                    // cout<<d<<" "<<x<<" "<<y<<"\n";
                }
            }
            if(x+1 <= size-1 && y+1 <= size-1){
                if(board[x+1][y]==0 && board[x][y+1]==0 && board[x+1][y+1]==0){
                    STACK.push(make_tuple(2,x+1,y+1));
                    // cout<<d<<" "<<x<<" "<<y<<"\n";
                }
            }
        
        }
        else if(d==1){ //가로
            if(y+1 <= size-1){
                if(board[x][y+1]==0){
                    STACK.push(make_tuple(1,x,y+1));
                    // cout<<d<<" "<<x<<" "<<y<<"\n";
                }
            }
            if(x+1 <= size-1 && y+1 <= size-1){
                if(board[x+1][y]==0 && board[x][y+1]==0 && board[x+1][y+1]==0){
                    STACK.push(make_tuple(2,x+1,y+1));
                    // cout<<d<<" "<<x<<" "<<y<<"\n";
                    }
                }
        }
        else{ //대각선
            if(x+1 <= size-1){
                if(board[x+1][y]==0){
                    STACK.push(make_tuple(0,x+1,y));
                    // cout<<d<<" "<<x<<" "<<y<<"\n";
                }
            }
            if(y+1 <= size-1){
                if(board[x][y+1]==0){
                    STACK.push(make_tuple(1,x,y+1));
                    // cout<<d<<" "<<x<<" "<<y<<"\n";
                }
            }
            if(x+1 <= size-1 && y+1 <= size-1){
                if(board[x+1][y]==0 && board[x][y+1]==0 && board[x+1][y+1]==0){
                    STACK.push(make_tuple(2,x+1,y+1));
                    // cout<<d<<" "<<x<<" "<<y<<"\n";
                }
            }
        }
        // print_STACK();
        return;
    }

   
public:
    int find_paths(){
        cnt=0;
        while(STACK.size()){
            int d,x,y;
            while(true){
                d= get<0>(STACK.top());
                x= get<1>(STACK.top());
                y= get<2>(STACK.top());
                // cout<<d<<" "<<x<<" "<<y<<"\n";
                if(x==size-1 && y==size-1){
                    STACK.pop();
                    cnt++;
                    continue;
                }
                else break;
            }
            // cout<<d<<" "<<x<<" "<<y<<"\n";
            STACK.pop();
            seek(d,x,y);
        }
        return cnt;
    }
        
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
    PIPE p;
    p.init();
    cout<<p.find_paths();

    return 0;
}