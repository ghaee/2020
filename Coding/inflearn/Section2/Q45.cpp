#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char** argv){
    int n,k, cnt=0, i=0, out=0;

    scanf("%d %d", &n,&k);
    vector<int> v(n+1);
    queue<int> q;
    
    for(int i = 1; i <= n; ++i){
        q.push(i);
    }
    while(q.size()){
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

    // while(true){
    //     i++;
    //     if(i > n) i = 1;
    //     if(v[i] == 0){ //아직 남아있는 사람들 중에
    //         cnt++;
    //         if(cnt == k){ //k번째에 해당하는 사람은
    //             v[i] = 1; //아웃됨
    //             cnt = 0; //초기화
    //             out++;
    //         }
    //     }
    //     if(out == n-1){ //한 명 빼고 다 아웃되면
    //         break; 
    //     }
    // }

    // for(int j = 1; j <=n; ++j){
    //     if(v[j] == 0) printf("%d",j);
    // }
    return 0;
}