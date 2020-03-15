**Sorting**

#### K번째 수
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for(int i = 0; i < commands.size(); ++i){
        int x = commands[i][0];
        int y = commands[i][1];
        int z = commands[i][2];

        tmp.assign(array.begin()+(x-1),array.begin()+y); **주어진 벡터를 잘라내어 새로 할당하는게 포인트**
        sort(tmp.begin(),tmp.end());
        
        answer.push_back(tmp[z-1]);
    }
    return answer;
}
```

#### 가장 큰 수
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
