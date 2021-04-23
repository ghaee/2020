#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int check[11], path[11];
int n, m, sum=0, cnt=0;
void dfs(int k, int sum){
    if(k == n+1){
        if(sum == m){
            cnt++;
            for(int i = 1; i < k; ++i){
                cout << path[i] <<" ";
            }
            cout << endl;
        }
    } 
    else{
        //+
        path[k] = check[k];
        dfs(k+1, sum+check[k]);
        //-
        path[k] = -check[k];
        dfs(k+1, sum-check[k]);
        //x
        path[k] = 0;
        dfs(k+1, sum);
    }
}

int main(int argc, char** argv){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> check[i];
    }
    dfs(1,0);
    if(cnt == 0) cout << -1;
    else cout << cnt;
    system("PAUSE");
    return 0;
}