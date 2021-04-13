#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//dynamic programming

int main(){
    int h, w;
    cin >> h >> w;

    vector<vector<int>> v(h+1,vector<int>(w+1));
    vector<vector<int>> dp(h+1,vector<int>(w+1));

    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            cin >> v[i][j];
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+v[i][j];
        }
    }

    int n, m;
    cin >> n >> m;

    int tmp=0, max = -2147000000;
    for(int i = n; i <= h; ++i){
        for(int j = m; j <= w; ++j){
          tmp = dp[i][j]-dp[i-n][j]-dp[i][j-m]+dp[i-n][j-m];
          if(tmp > max) max = tmp;
        }
    }
    cout << max << endl;
    return 0;
}