**PRACTICE**

#### 폰켓몬
```c++
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0; int tmp = 0;
    int n = nums.size();
    int k = n/2;
    sort(nums.begin(),nums.end());
    for(int i = n; i > 0; --i){
        if(nums[i-1] != nums[i]){
            answer++;
            k--;
        }
        if(k <= 0 )
            break;
    }
	return answer;
}
```

#### 같은 숫자는 싫어
```c++
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
   for(int i = 1; i <= arr.size(); ++i){ //인덱스를 1부터 시작해서
       if(arr[i-1] != arr[i])			// 이전 인덱스와 비교 후 연속되지않으면 추가
           answer.push_back(arr[i-1]);
   }
   

    return answer;
}
```