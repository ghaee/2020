##C++ Kit Part 1 : Hash / 완주하지 못한 선수

제한 사항 중 
completion의 길이는 participant 의 길이보다 1 작다 -> 완주 못한 사람은 딱 한 명이다.  
동명이인의 경우를 잘 생각해야함  

>-> n에 비례하는 알고리즘 

solution  
1. 참가자 명단 <-> 완주자 명단을 비교한다. //문자열로 주어진다.  
2. 동명이인의 경우를 생각해서 참가자 명단 속 이름의 수를 카운팅한다. // Hash 구조  
3. 완주자 명단에서 등장한다면 카운트를 -1 한다.  
4. 최종 카운트가 1이라면 해당 이름의 선수가 완주하지 못한 선수다.  


C++ STL에서의 Hash Table을 구현해놓은 컨테이너  
**map vs unordered_map**  

|                | std::map                   | std::unordered_map |
|----------------|----------------------------|--------------------|
| Access Time    | O(logn)                    | O(1)               |
| Data Structure | (usual) Binary Search Tree | Hash Table         |
|                |                            |                    |


**Hash를 이용한 풀이**
```c++
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string,int> d; 
    for(auto& i: participant){ //read&write access O(1)
    	d[i]++; //key = name , value++;
    }

    for (auto& i: completion){ //read&write access O(1)
    	d[i]--;
    }
    for (auto& i: d){
    	if(i.second > 0){ //compare O(n)
    		answer = i.first;
    		break;
    	}
    }
    return answer;
}

```
**기존에 내가 풀었던 방법**
hash를 쓰지 않았음
```c++
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end()); //O(nlogn)
    sort(completion.begin(),completion.end());   //O(nlogn)
    
    for(int i = 0; i < participant.size(); ++i){
        if(completion[i] == participant[i])
          continue;
        else{
            answer = participant[i];
            break;
        }
    }
    return answer;
}
```
