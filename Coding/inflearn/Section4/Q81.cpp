#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//벨만 포드 Bellan-Ford Algorithm
/*
다익스트라와는 달리 음의 weight가 있어도 가능함

1. src와 다른 vertex 사이의 dist를 무한대로 초기화
2. 인접한 모든 egde 탐색, cost가 적다면 갱신
3. n-1번 반복한다 (n vertices, 최대 n-1 edges를 이용할 수 있다.)

 * 음의 사이클이 없어야만 적용가능한 알고리즘
 * 정렬, 인접 리스트등이 필요없음
*/
struct Edge
{
	int v1, v2, cost;
	Edge(int a, int b, int c){
		v1 = a; v2 = b; cost = c;
	}
};

int main(){
	int src, dst, n, m;
	int a,b,c;
	vector<Edge> v;
	cin >> n >> m;
    vector<int> dist(n+1,2147000000);
	for(int i = 1; i <= m; ++i){
		cin >> a >> b >> c;
		v.push_back(Edge(a,b,c));
	}

	cin >> src >> dst;
	dist[src] = 0;

	for(int i = 1; i < n; ++i){ //i : # of edges to (n-1)
		for(int j = 0; j < v.size(); ++j){ //j : vector iterator
			int x = v[j].v1; //start  v1 --- cost ---> v2
			int y = v[j].v2; // end
			int z = v[j].cost;
			if(dist[x] != 2147000000 && dist[x] + z < dist[y]){
				dist[y] = dist[x] + z;
			}
		}
	}

	for(int j = 0; j < v.size(); ++j){ //n edges를 모두 사용해야만하는 경우
	// 음의 사이클 존재
		int x = v[j].v1; //start  v1 --- cost ---> v2
		int y = v[j].v2; // end
		int z = v[j].cost;
		if(dist[x] != 2147000000 && dist[x] + z < dist[y]){
			cout << "-1" << endl;
			system("PAUSE");
			return 0;
		}
	}
	cout << dist[dst] << endl;
	system("PAUSE");
	return 0;
}