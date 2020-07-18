#### C++ Kit Part 3 : Sort / 가장 큰 수

solution   
1. 빈 문자열로 수를 초기화한다.  
2. 주어진 수의 목록을 정렬한다.(이어붙일 때, *크게 만드는 조건*으로) --> O(nlogn)  
3. 목록에서 하나씩 현재 수에 이어 붙인다.  
4. 모든 수를 다 사용할때까지 반복.  

>2.의 크게 만드는 조건 정하기  
길이가 다를 경우를 고려해서 두 수를 앞뒤로 각각 붙여봤을 때 둘 중 크게 만드는 수를 먼저 골라야함  
제한 사항에서 수의 크기를 1000이하로 정했기 때문에 비교할 길이를 4자리까지만 보면된다...????<<??python용인듯  

**풀이**
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b){
  string s1 = to_string(a)+to_string(b);
  string s2 = to_string(b)+to_string(a);

  return s1 > s2;
} 
string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(),numbers.end(),cmp); //-->O(nlogn)

    for(auto& i:numbers){//-->O(n)
    	answer += to_string(i);
    }
    
    return answer[0] == '0'? "0" : answer;
}
```


**기존에 내가 풀었던 방법**
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(string a, string b){
  return a+b > b+a;
    /***
    true -> continue;
    false -> swap;
    a+b의 경우가 더 커야 앞자리가 커짐
    b+a의 경우로하면 1의 자리쪽으로 커짐
    ***/
} 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> itos;
    for(int i: numbers) //string 타입으로 변환
        itos.push_back(to_string(i));
    
    //숫자 조합에 따른 정렬
    sort(itos.begin(),itos.end(),compare);
    
    if(itos[0] == "0"){
        return "0";
    }
    
    for(string i: itos){
        answer+= i;
    }
    
    return answer;
}
```

##차이점 
기본 틀은 같지만, 문자열 변환을 미리 해주지 않고 비교와 결합시에만 변환해주었다.  
맨 앞자리가 0인 경우도 삼항연산자로 비교적 간단히 처리함  