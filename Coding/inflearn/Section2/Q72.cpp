#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char** argv){
    int n,k, cnt=0, i=0, out=0;

    scanf("%d %d", &n,&k);
    queue<int> q;
    
    for(int i = 1; i <= n; ++i){
        q.push(i);
    }
    while(!q.empty()){
        if(q.size() == 1){ //한 명 남으면
            cout << q.front() << endl;
            q.pop();
            break;
        }
        for(int i = 1; i < k; ++i){
            q.push(q.front()); //k번째 찾을 때까지 뒤로 옮기기
            q.pop(); //뒤로 옮긴 후 pop
        }
        q.pop(); //k번째 pop
    }
    return 0;
}