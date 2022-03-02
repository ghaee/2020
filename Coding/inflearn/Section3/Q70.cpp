#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int dist[30], ch[30];

int main(int argc, char** argv){
    int n, m, x;
    int n1, n2;
    cin >> n >> m;

    vector<int> map[30];
    queue<int> q;
    for(int i = 1; i <= m; ++i){
        cin >> n1 >> n2;
        map[n1].push_back(n2);

    }
    q.push(1);
    ch[1] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i = 0; i < map[x].size(); ++i){
            if(ch[map[x][i]] == 0){
                ch[map[x][i]] = 1;
                q.push(map[x][i]);
                dist[map[x][i]] = dist[x]+1; // x에서 출발해서 map[x][i]까지 엣지  1 추가 (인접하니까)
            }
        }
    }
    for(int i = 2; i <= n; ++i){
        cout << i << " : " << dist[i] << endl;
    }
    system("PAUSE");
    return 0;
}