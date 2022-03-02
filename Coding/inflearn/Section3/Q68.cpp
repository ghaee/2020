#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//최소비용 dfs, weighted directed graph + pair 
int n, m;
int n1, n2, w, cost=2147000;
vector<pair<int,int>> map[21];
int check[21];

void dfs(int src, int sum){
    if(src == n){
        if(sum < cost){
            cost = sum;
        }
    }
    else{
        for(int i = 0; i < map[src].size(); ++i){
            if(check[map[src][i].first] == 0){
                check[map[src][i].first] = 1; 
                dfs(map[src][i].first, sum+map[src][i].second);
                check[map[src][i].first] = 0;
            }
        }
    }
}
int main(int argc, char** argv){
    cin >> n >> m;

    pair<int,int> p;

    for(int i = 1; i <= m; ++ i){
        cin >> n1 >> n2 >> w;
        map[n1].push_back(make_pair(n2,w));
    } 

    check[1] = 1; // check for it's from node #1 
    dfs(1,0);
    
    cout << cost << endl;
    //system("PAUSE");
    return 0;
}