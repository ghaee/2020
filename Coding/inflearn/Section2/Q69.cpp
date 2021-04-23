#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bfs 큐 구현하기
int queue[100];
vector<int> map[8];
int front = -1, back = -1, ch[8];
int main(int argc, char** argv){
    int n, m, tmp;
    
    for(int i=1; i <= 6; ++i){
        cin >> n >> m;
        map[n].push_back(m); // n <-> m 연결되어있음을 표현
        map[m].push_back(n);
    }
    queue[++back] = 1;
    ch[1] = 1;
    while(front < back){
        tmp = queue[++front];
        cout << tmp << " ";
        for(int i = 0; i < map[tmp].size(); ++i){
            if(ch[map[tmp][i]] == 0){
                ch[map[tmp][i]] = 1;
                queue[++back] = map[tmp][i];
            }
        }
    }
    system("PAUSE");
    return 0;
}