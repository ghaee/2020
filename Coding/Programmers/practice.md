**PRACTICE**

#### 폰켓몬
```
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