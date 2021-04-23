#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//최소비용 dfs, weighted directed graph + matrix
int n, m;
int n1, n2, w, cost=2147000;
int map[21][21];
int check[21];

void dfs(int src, int sum){
    if(src == n){
        if(sum < cost){
            cost = sum;
        }
    }
    else{
        for(int i = 1; i <= n; ++i){
            if(map[src][i] > 0 && check[i] == 0){
                check[i] = 1; 
                dfs(i, sum+map[src][i]);
                check[i] = 0;
            }
        }
    }
}
int main(int argc, char** argv){

    cin >> n >> m;

    for(int i = 1; i <= m; ++ i){
        cin >> n1 >> n2 >> w;
        map[n1][n2] = w;
    } 

    check[1] = 1; // check for it's from node #1 
    dfs(1,0);
    
    cout << cost << endl;
    //system("PAUSE");
    return 0;
}