#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//경로탐색 dfs, directed graph + vector
int n, m;
int n1, n2, cnt=0;
vector<int> map[21];
int check[21];

void dfs(int src){
    if(src == n) cnt++;
    else{
        for(int i = 0; i < map[src].size(); ++i){
            if(check[map[src][i]] == 0){
                /*
                인접행렬에서 i == 인접리스트에서 map[src][i]
                */
                check[map[src][i]] = 1; //직전 노드가 i라는 체크
                dfs(map[src][i]);
                check[map[src][i]] = 0; //한 회차의 dsf를 다 돌면 풀어줘야 다음 dfs 돌 때 지장 없음
            }
        }
    }
}
int main(int argc, char** argv){

    cin >> n >> m;

    for(int i = 1; i <= m; ++ i){
        cin >> n1 >> n2;
        map[n1].push_back(n2);
    } 

    check[1] = 1; // check for it's from node #1 
    dfs(1);
    
    cout << cnt << endl;
    //system("PAUSE");
    return 0;
}