**Hash**

#### 완주하지 못한 선수
```c++
#include <string>
#include <vector>
#include <algorithm>

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

#### 위장  
```c++
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> d;

    for(auto& i: clothes){
        d[i[1]]++;
    }
    
    for(auto& i: d){
        answer *= i.second+1; //각 종류당 이름의 수
        //headgear_1,headgear_2,headgear_x & eyewear_1,eyewear_x ==> 3 * 2
    }
    return answer-1;
    //headgear_x,eyewear_x 경우의 수 제외
}

```
#### 베스트 앨범

unordered_map으로 구현함, 하지만 정렬을 위해 vector를 씀  
이미 정렬되어있는 map, set 활용하는 법 익혀야함  
```c++
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    //first : 고유번호, second : 재생횟수
    return a.second > b.second;
}
bool compare_map_value(pair<string,int> a,pair<string,int> b){
    //first : 장르, second : 총 재생횟수
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    /*
    i : 고유번호
     - genres[i] 고유번호 i의 장르 - plays[i] 고유번호 i의 재생 횟수
    1. 장르별 총 재생횟수를 구한다 (가장 많이 재생된 장르 찾기 위해 정렬 필)
    2. 같은 장르 안에서 재생순 1~2위를 구한다. 재생순위 동일시 고유번호 낮은 순 (각 장르당 최대 2곡만 선별, 재생횟수 정렬 필)
    */
    
    unordered_map <string,int> g_cnt;
    //장르별 총 재생횟수 담을 컨테이너 <"장르", 재생횟수>
    unordered_map<string,vector<pair<int,int>>> summary;
    //<"장르",재생횟수, 고유번호>

    for(int i=0; i < genres.size(); ++i){
        g_cnt[genres[i]] += plays[i];
        //d["classic"] = 500 + 150 + 800 
        summary[genres[i]].push_back(make_pair(i,plays[i]));
        //summary["classic"] -> (0,500) (2,150)....

    }
    for(auto &i : summary){
        sort(i.second.begin(),i.second.end(),compare); //같은 장르 안에서 재생 순위 내림차순 정렬
        // for(int j = 0; j < i.second.size(); ++j){
        //     cout << i.first << " " << i.second[j].first <<" "<< i.second[j].second <<endl;
        // }
    }
    
    vector<pair<string,int>> v_g_cnt;
    v_g_cnt.assign(g_cnt.begin(),g_cnt.end());
    sort(v_g_cnt.begin(),v_g_cnt.end(),compare_map_value); 
    // 장르별 총 재생횟수 내림차 정렬, 가장 큰 재생횟수를 가진 장르부터 담을거임

   for(int i = 0; i <v_g_cnt.size(); ++i){
    string g = v_g_cnt[i].first;
       for(int j = 0; j < summary[g].size() && j < 2; ++j){
            //cout << summary[g][j].second <<endl;
           answer.push_back(summary[g][j].first);
       }
    }

    return answer;
}
```  

**vector<pair> 구조 이해**  
![vector<pair>](./vector_pair.png)    

