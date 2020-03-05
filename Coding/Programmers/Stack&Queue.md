**Stack/Queue**

#### 탑
```
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.push_back(0);
    int size = heights.size();
    for(int i = 1; i < size; ++i){
        for(int j = i-1; j >= 0; --j){
            if(heights[j] > heights[i]){
                answer.push_back(j+1); //인덱스가 0부터 시작, 탑의 번호는 1부터 시작
                break;
            }else if(j == 0){
                answer.push_back(0);
                break;
            }
        }
    }
    return answer;
}
```