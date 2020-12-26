**Hash**

#### 완주하지 못한 선수
```c++
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
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

#### 전화번호 목록  
```c++
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string str = "";
    unordered_map<string,int> d;
    
    for(auto& i: phone_book){
        str = "";
        for(int j = 0; j < i.size(); ++j){
            str += i[j];
            d[str]++;
            //이로써 d에는 phone_book 인덱스 외의 키도 갖게된다.
        }
    }
    
    for(auto& i: phone_book){
        //d가 아닌 phone_book인 이유 : d의 수많은 키 중에서 phone_book에 있는 키만 뽑아보겠다.
        if(d[i] > 1){
            answer = false;
            break;
        }
    }
    return answer;
}

```