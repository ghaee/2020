#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// bs로 최소용량 찾기  
int v[1001], n;

int check(int mid){
    int cnt=1, tmp=0;
    for(int i = 1; i <= n; ++i){
            if((tmp+v[i]) > mid){
                cnt++;
                tmp = v[i];
            }else tmp += v[i];
        }
    return cnt;
}

int main(int argc, char** argv){
    int  m, lt=1, rt=0, mid;
    int answer, max = -214700000;

    scanf("%d %d",&n, &m);

    for(int i = 1; i <= n; ++i){
        scanf("%d",&v[i]);
        rt += v[i];
        if(v[i] >= max) max = v[i];
    }
    
    while(lt <= rt){
        mid = (lt+rt)/2;
        if(check(mid) <= m && mid >= max){
            answer = mid;
            rt = mid -1;
        }else{
            lt = mid + 1;
        }
    }
    printf("%d", answer);
	return 0;
}