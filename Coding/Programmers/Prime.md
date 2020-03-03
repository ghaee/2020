**Prime**

#### 1~n 사이 소수 개수 구하기  
-에라토스테네스의 체 사용  
```
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int *arr = new int[n+1]; //n의 사이즈를 갖는 배열 선언
    
    for(int i = 0; i < n+1; ++i){
        arr[i] = 1; //1~n까지 모두 소수라고 가정
    }
    
    for(int i = 2; i < n+1; ++i){
        if(arr[i] == 1){
            if((unsigned int)pow(i,2) > 1000001){
                break;
            }
            else{
                for(int j = (int)pow(i,2); j < n+1; ){ //소수(i)의 배수들은
                    arr[j] = 0; //소수가 아니다
                    j = j + i;
                }
            }
        }
    }
    for(int i = 2; i < n+1; ++i){
        if(arr[i] == 1)
            answer++;
    }
    delete []arr;
    return answer;
}
```