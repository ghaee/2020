#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//미로탐색 dfs, directed graph
int n, m;
int n1, n2, cnt=0;
int map[8][8] = {0,};
int check[8][8];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y){
    int x2, y2;
    if(x == 7 && y == 7){
        cnt++;
    }else{
        for(int i = 0; i <4; ++i){
            x2 = x + dx[i];
            y2 = y + dy[i];
            if(x2 < 1 || x2 > 7 || y2 < 1 || y2 >7) continue;
            if(map[x2][y2] == 0 && check[x2][y2] == 0){
                check[x2][y2] = 1;
                dfs(x2,y2);
                check[x2][y2] = 0;
            }
        }
    }
}

int main(int argc, char** argv){

    for(int i = 1; i <= 7; ++i){
        for(int j = 1; j <= 7; ++j){
            cin >> map[i][j];
        }
    } 

    check[1][1] = 1; // check for it's from node #1 
    dfs(1,1);
    
    cout << cnt << endl;
    //csystem("PAUSE");
    return 0;
}