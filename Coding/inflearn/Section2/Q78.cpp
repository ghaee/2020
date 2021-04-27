#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//Kruskal MST with Union & Find
/*
1. sort cost by ascending order
2. check if current edge make cycle
3. if not, include in the MST
*/ 
int mst[201];

struct Make_edge{
    int v1, v2, cost;
    Make_edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        cost = c;
    }
    bool operator<(Make_edge &b){
        return cost < b.cost;
    }
};

int Find(int a){
    if(a == mst[a]) return a;
    else return mst[a] = Find(mst[a]); //memoization
}

void Union(int a, int b){
    //if they belong to different set(different root node)
    a = Find(a);
    b = Find(b);
    if(a != b){
        mst[a] = b; // Union 
    }
}

int main(int argc, char** argv){
    vector<Make_edge> ed;
    int v, e, a, b, c, cnt = 0;
    
    cin >> v >> e;
   
    //initialize all vertices to belong to their own set
    for(int i = 1; i <= v; ++i){
        // index 'i' : student neumber
        mst[i] = i;
        //i-th element : set number 
    }
    for(int i = 1; i <= e; ++i){
        cin >> a >> b >> c;
        ed.push_back(Make_edge(a,b,c));
    }
    sort(ed.begin(),ed.end()); // 1. sort by ascending order
    
    for(int i = 0; i < e; ++i){// 2. check if current edge make cycle
        int fa = Find(ed[i].v1);
        int fb = Find(ed[i].v2);
        if(fa != fb){ // 3. if not, include in the MST
            cnt += ed[i].cost;
            Union(ed[i].v1, ed[i].v2);
        } 
    }
    cout << cnt << endl;
    return 0;
}