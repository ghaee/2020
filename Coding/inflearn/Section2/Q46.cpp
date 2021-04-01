#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
    int n,k, i=0, sec=0, cnt = 0;

    vector<int> v(n+1);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d\n", &v[i]);
        sec += v[i];
    }    
    scanf("%d", &k);
    if(k >= sec){ printf("-1"); return 0;}
    
    while(true){
        i++;
        if(i > n){
            i = 1;
        }
        if(v[i] != 0){
            v[i]--;
            cnt++;
        }
        if(cnt == k){ //정전
           break;
        }
    }
    //정전 후 다시 작업 재개
    while(true){
        i++;
        if(i > n){
            i = 1;
        }
        if(v[i] != 0){
            printf("%d\n",i);
            break;
        }
        
    }
    //system("PAUSE");
    return 0;
}