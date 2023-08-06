#include <iostream>
#include <vector>
#include <queue>
#define INF 1<<20
using namespace std;

int V,E,start;
vector<pair<int,int> >* graph;
int* minlist;


void init(){
    cin>>V>>E>>start;
    graph = new vector<pair<int,int> >[V+1]();
    minlist = new int[V+1];
    fill(minlist,minlist+V,INF);
    
    int from,to,dist;
    for(int i=0;i<E;i++){
        cin>>from>>to>>dist;
        graph[from].push_back(make_pair(to,dist));
    }
    
}

void dijkstra(int start){
    priority_queue<pair<int,int> > det;

    det.push(make_pair(0,start)); //첫번째 기준으로 !내림차순! 비교연산하므로 거리를 첫번째 원소에 둔다.
    minlist[start] = 0; //오름차순이 필요하므로 거리는 -를 곱해서 push함.
    while(!det.empty()){
        int dist = -det.top().first;
        int curnode = det.top().second;
        det.pop();

        if(minlist[curnode]<dist) continue;
 
        for(int i=0;i<graph[curnode].size();i++){
            dist += graph[curnode][i].second;

            if(dist < minlist[graph[curnode][i].first]){
                minlist[graph[curnode][i].first] = dist;
                det.push(make_pair(-dist,graph[curnode][i].first));
            }
        }
    }
}

int main(){
    init();
    dijkstra(start);
    for(int i=1;i<V+1;i++){
        minlist[i] == INF ? cout<<"INF\n" : cout<<minlist[i]<<"\n";
    }

    delete minlist;
    return 0;
}