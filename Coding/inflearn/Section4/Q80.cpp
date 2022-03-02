#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
Dijkstra Algorithm

1. dist[] initialize to infinite cost
2. set any vertex to start
3. if next cost is lower than current, update dist[]
*/
struct Edge{
	int v, cost;
	Edge(int a, int b){
		v = a;
		cost = b;
	}
	bool operator <(const Edge &b) const{
		return cost > b.cost; //priority_queue, min heap
	}
};
int main(){
	int n, m, a, b, c, cnt = 0;
	//int *dist;
	cin >> n >> m;

	priority_queue<Edge> pq;
	vector<pair<int,int>> map[n+1];
	vector<int> dist(n+1,2147000000);
	for(int i = 1; i <= m; ++i){
		cin >> a  >> b >> c;

		//v1 ---- weight ----> v2 directed graph
		map[a].push_back(make_pair(b,c));
	}

	pq.push(Edge(1,0)); 
	dist[1] = 0;
	while(!pq.empty()){
		int cur = pq.top().v;
		int weight = pq.top().cost;
		pq.pop();

		if(weight > dist[cur]) continue;
		for(int i = 0; i < map[cur].size(); ++i){
			int next = map[cur][i].first;
			int next_w = weight + map[cur][i].second;
			if(dist[next] > next_w){
				dist[next] = next_w;
				pq.push(Edge(next,next_w));
			}

		}
	}

	cout << "===================================" << endl;
    for(int i = 2; i <= n; ++i){
        if(dist[i] != 2147000000) cout << i << " : " << dist[i] << endl;
        else{ cout << i << " : impossible" << endl;}
    }
    cout << "===================================" << endl;

	system("PAUSE");
	return 0;
}