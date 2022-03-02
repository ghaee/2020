#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
/*
Prim Algorithm (Greedy / MST)
with priority_queue
1. set any vertex to start with MST
2. select the next vertex at minimum cost
3. iterate til the MST has (v-1) edges * v : the number of vetices
*/

int *mst;

struct Edge{
	int v1, cost;
	Edge(int a, int c){
		v1 = a;  cost = c;
	}
	bool operator < (const Edge &b) const {
		return cost > b.cost;
	}
};

int main(){
	priority_queue<Edge> pq;
	int n, e, v1, v2, w, cnt = 0;
	cin >> n  >> e;

	mst = new int[n+1]{0,}; //initialize to 0
    vector<pair<int,int>> map[n+1];
	for(int i = 1; i <= e; ++i){
		cin >> v1 >> v2 >> w;

		//v1 <---- weight ----> v2 undirected graph
		map[v1].push_back(make_pair(v2,w));
		map[v2].push_back(make_pair(v1,w));
	}

	pq.push(Edge(1,0));

	while(!pq.empty()){
		Edge tmp = pq.top();
		int vertex = tmp.v1;
		int weight = tmp.cost;

		pq.pop();

		if(mst[vertex] == 0){ //not included in the minumum spanning tree yet
			cnt += weight;
			mst[vertex] = 1;
			for(int i = 0; i < map[vertex].size(); ++i){ //현재 vertex에서 뻗을 수 있는 인접 vertex 추가
				pq.push(Edge(map[vertex][i].first,map[vertex][i].second));
			}
		}
	}

	cout << cnt << endl;
    delete[] mst;
	//system("PAUSE");
	return 0;
}