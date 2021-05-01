#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
// Dijkstra Algorithm

struct MakeEdge{
    int v, c;
    MakeEdge(int b, int x){
        v = b;
        c = x;
    }
    bool operator < (const MakeEdge &b) const {
        return c > b.c; //min heap
    }
};

int main(int argc, char** argv){
    int v, e, a, b, c, sum = 0;
    
    priority_queue<MakeEdge> pq;
    vector<pair<int,int>> map[30];
    
    cin >> v >> e;
    vector<int> dist(v+1,2147000000); // initialize all vertices to infinite value
    for(int i = 1; i <= e; ++i){
        cin >> a >> b >> c;

        // directed graph 인접리스트 만들기
        map[a].push_back(make_pair(b,c));
    }   
    
    pq.push(MakeEdge(1,0)); //임의의 시작 vertex
    dist[1] = 0;
    while(!pq.empty()){
        int now = pq.top().v;
        int cost = pq.top().c;
        pq.pop();
        if(cost > dist[now]) continue;
        for(int i = 0; i < map[now].size(); ++i){ 
            int next = map[now][i].first;
            int next_dist = cost + map[now][i].second;
            if(dist[next] > next_dist){ // 현재 cost 보다 낮은 값이 있다면
                dist[next] = next_dist; //갱신
                pq.push(MakeEdge(next,next_dist));//인접 vertex 큐에 추가
            }
        }
    }
    cout << "===================================" << endl;
    for(int i = 2; i <= v; ++i){
        if(dist[i] != 2147000000) cout << i << " : " << dist[i] << endl;
        else{ cout << i << " : impossible" << endl;}
    }
    cout << "===================================" << endl;
    system("PAUSE");
    return 0;
}