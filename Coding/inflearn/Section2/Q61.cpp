#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int check[11];
int n, m, sum=0, cnt=0;
int dfs(int k, int sum){
    if(k == n+1){
        if(sum == m){
            cnt++;
        }
    } 
    else{
        //+
        dfs(k+1, sum+check[k]);
        //-
        dfs(k+1, sum-check[k]);
        //x
        dfs(k+1, sum);
    }
    return cnt;
}

int main(int argc, char** argv){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> check[i];
    }
    dfs(1,0);
    if(cnt == 0) cout << -1;
    else cout << cnt;
    //system("PAUSE");
    return 0;
}