#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//vector 2차원 동적할당

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(int argc, char** argv){
    int n,cnt=0;
    bool peak;

    cin >> n;
    vector<vector<int>> v(n+2, vector<int>(n+2, 0));

    for(int i =1; i <= n; ++i){
        for(int j = 1; j <=n; ++j){
            cin >> v[i][j];
        }
    }
    for(int i =1; i <= n; ++i){
        for(int j = 1; j <=n; ++j){
            peak = true;
            for(int k =0; k < 4; ++k){
                if(v[i][j] <= v[i+dx[k]][j+dy[k]]){
                    peak = false;
                    break;
                }
            }
            if(peak) cnt++;
        }
    }

    cout << cnt <<endl;
    return 0;
}