#### C++ Kit Part 2 : Greedy / 체육복

제한 사항 중  
앞뒤 학생에게만 빌려줄 수 있기 때문에 빌려줄 학생들을 순서대로 살펴야하고  
이 순서에 따라 우선하여 빌려줄 방향(-> or <-)을 정해야 최적의 해를 구할 수 있음  

solution 1 : 학생의 수가 30이하인 점(n<=30)을 고려해 학생 수만큼의 배열 확보 후 체육복 개수 입력 후 탐색, 번호 순대로 --> O(n)  
>전체 학생의 수가 매우 크고 reserve의 수가 굉장히 적다면 효율이 낮아진다.  빌려줄 체육복은 없는데에도 모든 학생의 탐색을 돌아야하기 때문

solution 2 : (크기가 k인) reserve를 정렬하고 빌려줄 학생을 찾는다. --> O(klogk)
>만약 n과 k의 차이가 크지 않다면 solution 1의 복잡도가 더 낮지만 n은 크고 k는 작을 경우 solution 2의 복잡도가 더 낮다.    
빌려줄 학생을 찾을 때엔 hash를 이용해서 복잡도를 유리하게 가져간다.   

**solution 1**  
O(n)
```c++
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    int answer = 0;
    vector<int> u(n+2,1);
    for (int i = 0; i < reserve.size(); ++i)
    {
       u[reserve[i]]++;
    }
    for (int i = 0; i < lost.size(); ++i)
    {
       u[lost[i]]--;
    }

    for(int i = 1; i <=n; ++i){
        if(u[i-1] == 0 && u[i] == 2){
            u[i-1] = u[i] = 1;
        }
        else if(u[i] == 2 && u[i+1] == 0){
            u[i+1] = u[i] = 1;
        }
    }

    for(int i = 1; i <= n; ++i){
        if(u[i] > 0) answer++;
    }
}
```

**solution 2**  
O(klogk)
```c++


using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    unordered_set<int> l(lost.begin(),lost.end()); //lost
    set<int> r; //reserve 번호 순서가 유효해야함
    unordered_set<int> inter; //intersection between l and r

    for(auto& i : reserve){ //-->reserve의 크기(k)만큼 시간복잡도 O(k)
        if(l.find(i) == l.end()) //--> find()는 O(1) | reserve but not lost
            r.insert(i); //--> O(logk)
        else
            inter.insert(i); //-->O(k)
    }
    //--> for loop 전체의 복잡도는 O(klogk)

    for(auto& i : inter){ //inter의 학생들은 빌릴 필요 없음
        l.erase(i); //-->O(1) unordered니까
    }

    for(auto& i : r){ //-->O(k) | 빌려줄거야
        if(l.find(i-1) != l.end()) //내 앞 사람이 lost했다면
            l.erase(i-1); //빌려줌
        else if(l.find(i+1) != l.end())
            l.erase(i+1);
    }

    return n - l.size();
}
```


**기존에 내가 풀었던 방법**
O(n^2)
```c++
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