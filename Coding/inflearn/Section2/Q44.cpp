#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// bs로 최대거리 찾기 
int n;

int check(int mid, vector<int> v){
    int cnt=1, tmp=v[0];
    for(int i = 1; i < n; ++i){
        if((v[i]- tmp) >= mid){
            tmp = v[i];
            cnt++;
        }
    }
    return cnt;
}


int main(int argc, char** argv){
    int c, lt, rt, mid;
    int tmp, answer, max = -214700000;

    scanf("%d %d",&n, &c);
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&v[i]);
    }
    sort(v.begin(),v.end());
   
    lt = v.front();
    rt = v.back();
    
    while(lt <= rt){
        mid = (lt+rt)/2;
        if(check(mid,v) >= c){
            answer = mid;
            lt = mid + 1;
            //lt를 증가함으로써 mid 값도 증가함, 이 연산을 할 수록
            //거리가 더 먼 조건을 충족시킬 수 있음
        }else{
            rt = mid -1;
        }
    }
    printf("%d\n", answer);
    //system("PAUSE");
	return 0;
}