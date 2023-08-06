#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Graph{
    int size;
    bool** adja;
    int firstnode;

    public:

    Graph(int N,int edges,int first){
        firstnode = first-1;
        size = N;
        adja = (bool**)calloc(size,sizeof(bool*));
        for(int i=0;i<size;i++){
            adja[i] = (bool*)calloc(size,sizeof(bool));
        }
        set_edge(edges);

    }
    void set_edge(int edges){
        int src,dest;
        for(int i=0;i<edges;i++){
            scanf("%d %d",&src,&dest);
            adja[src-1][dest-1] = true;
            adja[dest-1][src-1] = true;
        }
    }
    void BFS(){
        queue<int> T;
        int* color = (int*)calloc(size,sizeof(int));

        T.push(firstnode);
        int idx = 0;
        int cur,i;
        while(T.size() != 0){
            cur = T.front();
            T.pop();
            cout<<cur+1<<" ";

            for(i=0;i<size;i++){
                if(adja[cur][i]==true && color[i]==0){
                    T.push(i);
                    color[i] = 1;
                }
            }
            color[cur] = 2;
        }
        cout<<"\n";
    }
    void DFS(){
        stack<int> T;
        int* color = (int*)calloc(size,sizeof(int));
        int cur,i;

        DFSvisit(firstnode,color);

        for(i=0;i<size;i++){
            if(color[i]==0){
                DFSvisit(i,color);
            }
        }
    }

    void DFSvisit(int node,int* color){
        color[node] = 1;
        cout<<node+1<<" ";
        for(int i=0;i<size;i++){
            if(adja[node][i] == true && color[i] == 0){
                DFSvisit(i,color);
            }
        }
        color[node] = 2;
        return;
    }
};

int main(){
    int N,edges,first;
    scanf("%d %d %d",&N,&edges,&first);
    Graph G(N,edges,first);
    G.DFS();
    cout<<"\n";
    G.BFS();
    return 0;
}