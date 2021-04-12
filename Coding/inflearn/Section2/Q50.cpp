#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    vector<vector<int>> v(h+1,vector<int>(w+1));

    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            cin >> v[i][j];
        }
    }

    int n, m;
    cin >> n >> m;

    int sum=0, max = -2147000000;
    for(int i = 1; i <= h-n+1; ++i){
        for(int j = 1; j <= w-m+1; ++j){
            sum = 0;
            for(int k = i; k < i+n; ++k){
                for(int x = j; x < j+m; ++x){
                    sum += v[k][x];
                }
            }
            if(sum > max){
                max = sum;
            }
        }
    }
    cout << max << endl;
    return 0;
}