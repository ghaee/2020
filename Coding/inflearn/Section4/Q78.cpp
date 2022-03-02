#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
Kruskal Algorithm (Greedy / MST)

1. sort cost by ascending order
2. check cycle by using Union&Find
3. if not, push MST
*/
int *mst;

struct Edge
{
	int v1, v2, cost;
	Edge(int a, int b, int c){
		v1 = a; v2 = b; cost = c;
	}

	bool operator<(Edge &b){ //sort by ascending order
		return cost < b.cost;
	}
};

int Find(int a){
	if(a == mst[a]) return a;
	else return mst[a] = Find(mst[a]); //memoization
}

void Union(int a, int b){
	a = Find(a); b = Find(b);
	if(a!=b){
		mst[a] = b;
	}
}

int main(int argc, char** argv){
	vector<Edge> v;
	int n, e, v1, v2, w, cnt = 0;
	cin >> n >> e;
	mst = new int[n+1];
	
	//set *initialize all vertices to belong to their own set
	for(int i = 1; i <= n; ++i){
		mst[i] = i;
	}

	//edge
	for(int i = 1; i <= e; ++i){
		cin >> v1 >> v2 >> w;
		v.push_back(Edge(v1,v2,w));
	}

	sort(v.begin(),v.end());

	for(int i = 0; i < e; ++i){
		int x = Find(v[i].v1);
		int y = Find(v[i].v2);
		if(x != y){ // they are from different set(NO CYCLE)
			cnt += v[i].cost;
			Union(x,y);
		}
	}

    cout << cnt << endl;
	//system("PAUSE");
	return 0;
}