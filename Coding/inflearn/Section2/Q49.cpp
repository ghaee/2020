#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, sum=0;
    cin >> n;

    vector<vector<int>> v(n+1,vector<int>(n+1, 0));
    vector<int> tmp(n+1);

    //front
    for(int i = 1; i <= n; ++i){
        scanf("%d",&tmp[i]);
    }

    //일단 정면 데이터를 기본으로 할당한 뒤
    for(int i = 1; i <= n;  ++i){
        for(int j = 1; j <= n; ++j){
            v[j][i] = tmp[i];
        }
    }

    //right
    for(int i = 1; i <= n; ++i){
        scanf("%d",&tmp[i]);
    }

    //측면 데이터와 비교, 측면 값보다 크다면 조정
    for(int i = 1; i <= n;  ++i){
        for(int j = 1; j <= n; ++j){
           if(v[i][j] > tmp[i]) v[i][j] = tmp[i];
        }
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <=n; ++j){
            sum += v[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}