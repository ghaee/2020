#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//Prim MST with priority_queue
/*
1. set any vertex to start with MST
2. select the next vertex at minimum cost
3. iterate til the MST has (v-1) edges * v : the number of vetices
*/
int mst[30];
struct MakeEdge{
    int v, cost;
    MakeEdge(int b, int c){
        v = b;
        cost = c;
    }
    bool operator < (const MakeEdge &b) const {
        return cost > b.cost; //min heap
    }
};

int main(int argc, char** argv){
    int v, e, a, b, c, sum = 0;
    priority_queue<MakeEdge> pq;
    vector<pair<int,int>> map[30];

    cin >> v >> e;
    for(int i = 1; i <= e; ++i){
        cin >> a >> b >> c;

        // a<--c-->b 인접리스트 만들기
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
    }   
    pq.push(MakeEdge(1,0)); //임의의 시작 vertex
    
    while(!pq.empty()){
        MakeEdge tmp = pq.top();
        pq.pop();
        int vertex = tmp.v;
        int cost = tmp.cost;
        if(mst[vertex] == 0){ 
            sum += cost;
            mst[vertex] = 1; //including mst
            for(int i = 0; i < map[vertex].size(); ++i){ //인접 vertex 큐에 추가
                pq.push(MakeEdge(map[vertex][i].first,map[vertex][i].second));
            }
        }
    }
    cout << sum << endl;
    return 0;
}