**Greedy**

#### 체육복
```
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int i,j;
    for(i = 0; i < lost.size(); ++i){
        for(j = 0; j < reserve.size(); ++j){
            if(lost[i] == reserve[j]){ //reserve가 lost했다면 못 빌려줌
                reserve[j] = 0; //0이면  못빌려줌
                lost[i] = 0; //못 빌려주는데 자기는 입을 수 있음
            }
        }
    }
    for(i = 0; i < lost.size(); ++i){
        for(j = 0; j < reserve.size(); ++j){
            if(reserve[j] != 0)
                if(lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]){ //if adjacent
                    reserve[j] = 0;
                    lost[i] = 0;
                }
        }
        if(lost[i] != 0)
            --n;
    }
    return n;
}
```