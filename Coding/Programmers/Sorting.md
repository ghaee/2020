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
