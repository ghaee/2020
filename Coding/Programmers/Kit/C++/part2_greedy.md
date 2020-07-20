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

#### C++ Kit Part 4 : Greedy / 큰 수 만들기  

제한 사항 중    
큰 수를 앞에, 작은 수를 뒤에 두게끔 *순서대로* 지워야한다.  
순서대로 숫자를 지워가다가 현재보다 크거나 같은 수가 나오면 지우지않고 남긴다.   
주어진 개수만큼 지울 때까지 반복한다.  
**주의**  
만약 주어진 숫자가 처음부터 큰->작은 순으로 정렬되어있다면 뒤에서부터 지워야한다.  

solution:
1. 주어진 숫자로부터 하나씩 꺼낸다. 이 때 이미 꺼낸 수 중에 현재의 수보다 작은 수가 있다면 그 작은 수를 지운다.  
2. k번 반복한다.   
3. 숫자를 모두 비교했는데도 k의 개수를 채우지 못했다면 남은 수의 뒤부터 지워가며 k를 충족한다.  

>1에서 대소 비교를 할 때 전체를 다 비교할 필요가 없다. 직전에 꺼낸 수와 비교하면된다.   
WHY? 꺼낸 수 중에 남은 수들은 이미 큰->작은 순으로 정렬되어있을테니까.  

##### 탐욕법 Greedy Approach  
- 앞 단계에서의 선택이 이후 단계에서의 선택과 솔루션의 최적성(optimality)에 영향을 주지 않음  
- 일단 뒤를 생각하지않고 지금 현재 최적의 솔루션을 채택한 것이 마지막까지 가면 최적의 솔루션이된다.  
- ***모든 경우의 수를 따져보지 않아도 순서대로 진행하면서 그 때 그 때의 최적의 선택이 최종적으로 최적의 솔루션이다.***   

**solution**   
O(n)  
```c++
#include <string>
#include <vector>
using namespace std;

int solution(string number, int k) {
    string s = ""; //number에서 꺼내어 s에 모아둔다.

    for(int i=0; i < number.length(); ++i){ //-->O(n)
        while(!s.empty() && s.back() < number[i] && k > 0){ //-->O(2n)
            //아직 제거해야하는 숫자가 남았고 (k>0)
            //꺼낸 수 중 직전의 수가 현재의 수보다 작으면
            s.pop_back(); //그 작은, 직전의 수를 지운다.  
            --k;
        }
        if(k == 0){ //뺄 만큼 뺐으면 반복문 종료
            s += number.substr(i,number.length()-1);
            break;
        }
        s.push_back(number[i]); //그리고 지금 꺼낸 수를 남겨둔다.  
    }

    return s.substr(0,s.length()-k); //더 빼야하는 수가 남았다면 뒤에서부터 제거한다.  
}
``` 