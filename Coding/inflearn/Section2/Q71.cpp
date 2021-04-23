#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int ch[10001];
int d[3] = {1, -1, 5};
int main(int argc, char** argv){
    int S, E, x, loc;
    cin >> S >> E;

    vector<int> map[30];
    queue<int> q;
    q.push(S);
    ch[S]=1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i = 0; i < 3; ++i){
            loc = x+d[i];
            if(loc <= 0 && loc > 10000) continue;
            if(loc == E){
                cout << ch[x] << endl;
                //system("PAUSE");
                return 0;
            }if(ch[loc] == 0){
                ch[loc] = ch[x]+1; //현재 위치에서부터 loc까지의 엣지 수
                q.push(loc);
            }
        }
    }
    return 0;
}