#include <stdio.h>
int board[19][19];
void printboard(){
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int check(int i,int j){
    
    /* 오른쪽방향 */
    if(j<15){
        if(board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] 
        && board[i][j+3] == board[i][j+4]){
            if(j==14){
                if(board[i][j-1]!=board[i][j]) return 1;
            }
            else if(j==0){
                if(board[i][j] != board[i][j+5]) return 1;
            }
            else if(board[i][j-1]!=board[i][j] && board[i][j] != board[i][j+5]) return 1;
        }
    }
    /* 아래방향 */
    if(i<15){
        if(board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+2][j] == board[i+3][j] 
        && board[i+3][j] == board[i+4][j]){
            if(i==14){
                if(board[i-1][j]!=board[i][j]) return 1;
            }
            else if(i==0){
                if(board[i][j] != board[i+5][j]) return 1;
            }
            else if(board[i-1][j]!=board[i][j] && board[i][j] != board[i+5][j]) return 1;
        }
    }
    /* 대각오른쪽아래방향 */
    if(i<15 && j<15){
        if(board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3] 
        && board[i+3][j+3] == board[i+4][j+4]){
            if((j==14 && i!=0) || (i==14 && j!=0)){
                if(board[i-1][j-1]!=board[i][j]) return 1;
            }
            else if((j==0 && i!=14) || (i==0 && j!=14)){
                if(board[i][j] != board[i+5][j+5]) return 1;
            }
            else if(board[i-1][j-1]!=board[i][j] && board[i][j] != board[i+5][j+5]) return 1;
        }
    }
    /* 대각오른쪽위방향 */
    if(i>3 && j<15){
        if(board[i][j] == board[i-1][j+1] && board[i-1][j+1] == board[i-2][j+2] && board[i-2][j+2] == board[i-3][j+3] 
        && board[i-3][j+3] == board[i-4][j+4]){
            if((j==14 && i!=18) || (i==4 && j!=0)){
                if(board[i+1][j-1]!=board[i][j]) return 1;
            }
            else if((j==0 && i!=4) || (i==18 && j!=14)){
                if(board[i][j] != board[i-5][j+5]) return 1;
            }
            else if(board[i+1][j-1]!=board[i][j] && board[i][j] != board[i-5][j+5]) return 1;
        }
    }
    return 0;
}

int seek(int* row,int* col,int nonzero){
    int cnt = nonzero;
    for(int i=0;i<19 && cnt!=0;i++){
        for(int j=0;j<19 && cnt!=0;j++){
            if(board[i][j]!=0){
                if(check(i,j)){
                    *row = i;
                    *col = j;
                    return 1;
                }
                cnt--;
            }
        }
    }
    return 0;
}

int main(){
    int row,col;
    int nonzero=0;
    
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            scanf("%d",&board[i][j]);
            if(board[i][j]!=0) nonzero++;
        }
    }
    if(seek(&row,&col,nonzero)){
        printf("%d\n",board[row][col]);
        printf("%d %d",row+1,col+1);
    }
    else printf("0");



    return 0;
}