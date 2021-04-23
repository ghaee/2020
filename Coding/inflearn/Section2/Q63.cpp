#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char** argv){
    int n, m;
    int n1, n2, w;
    int map[20][20] = {0,};

    cin >> n >> m;

    for(int i = 1; i <= m; ++ i){
        cin >> n1 >> n2 >> w;
        map[n1][n2] = w;
    } 

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}