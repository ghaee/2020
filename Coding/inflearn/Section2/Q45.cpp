#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv){
    int n,k, cnt=0, i=0, out=0;

    scanf("%d %d", &n,&k);
    vector<int> v(n+1);

    while(true){
        i++;
        if(i > n) i = 1;
        if(v[i] == 0){ //아직 남아있는 사람들 중에
            cnt++;
            if(cnt == k){ //k번째에 해당하는 사람은
                v[i] = 1; //아웃됨
                cnt = 0; //초기화
                out++;
            }
        }
        if(out == n-1){ //한 명 빼고 다 아웃되면
            break; 
        }
    }

    for(int j = 1; j <=n; ++j){
        if(v[j] == 0) printf("%d",j);
    }
    return 0;
}