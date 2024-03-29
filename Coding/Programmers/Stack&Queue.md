**Stack/Queue**

#### 탑
```c++
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

#### 다리를 지나는 탑
```c++
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int truck = 0;
    int tmp = 0;
    queue<int> passing;
    
    for(int i = 0; i < truck_weights.size(); ++i){
        truck = truck_weights[i];
        while(true){
            if(passing.empty()){ //empty queue
                passing.push(truck);
                sum += truck;
                answer++;
                break;
            }else if(passing.size()==bridge_length){ //full queue
                //제일 앞에 있는 트럭이 다 지나갔다는 것을 의미함
                sum -= passing.front();
                passing.pop();
                
            }else{ //트럭 무게 고려하며 다리에 올라감
                tmp = sum + truck;
                if(tmp > weight){ //무게 초과, 시간만 지남
                    passing.push(0); //이걸 안하면 큐 사이즈 계산 제대로 안되어서 passing.pop()안됨
                    answer++;
                }else{
                    passing.push(truck);
                    sum = tmp;
                    answer++;
                    break;
                }
                
            }
        }
    }
    /*answer는 마지막 트럭이 올라간 시간을 의미함*/
    return answer+bridge_length;
}
```

#### 기능개발
```c++
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0; 
    vector<int> complete;
    int tmp = 0;
    double days;
    for(int i = 0; i < progresses.size(); ++i){
        days = (double)(100-progresses[i]) / speeds[i];
        complete.push_back(ceil(days));
    }
    tmp = complete[0]; //비교 대상을 첫 기능으로 고정
    for(int i = 0; i < complete.size(); ++i){
        if(tmp < complete[i]){ //첫 기능보다 오래걸리는 작업나오면
            answer.push_back(cnt); //여태 카운팅한거 저장하고
            cnt = 1; //초기화 (i번째 기능 배포했기때문에 1)
            tmp = complete[i]; //비교 대상을 바꿔준다
        }else{
            cnt++;
        }
        if(i == complete.size()-1)
            answer.push_back(cnt);
    }
    
    return answer;
}
```