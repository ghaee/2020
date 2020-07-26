#### C++ Kit Part 6 : Dynamic Programming / N으로 표현  

Dynamic Programming  
- 문제의 답인지 확인하는 과정에서 탐색의 범위를 동적으로 결정하는 것  

>  1. 주어진 최적화 문제를 재귀 방식으로 보다 작은 부분 문제로 나누어 문제를 푼다.  
>  2. 이 해를 조합하여 문제의 최종 해답에 이른다.   
>  3. 알고리즘의 진행에 따라 탐색해야할 범위를 동적으로 결정함으로써 탐색 범위를 한정할 수 있음    

**Ex.피보나치 수열의 예**     

1) 재귀함수로 구현한다면?  
f(4) = f(3)		      +f(2)  
	 = f(2)	    +f(1) +f(1)+f(0)  
	 = f(1)+f(0)+f(1) +f(1)+f(0)  
O(logN)   

2) Dynamic Programming  
f(0)=0, f(1)=1    
f(2)=f(1)+f(0)=1    
f(3)=f(2)+f(1)=2  
f(4)=f(3)+f(2)=3  

--> 부분문제의 답을 먼저 알아낸 후 최종 문제의 답에 이용한다.  
O(N)   


**문제: N으로 표현**
N번 써서 만들 수 있는 수의 가짓수를 모두 갖고 있다.  
그런 다음 원하는 숫자가 어느 그룹에 속하는지(N=1,2,3..) 찾으면 그 N이 답.  
N=5일 때,  
| # of N | possible numbers                              |
|--------|-----------------------------------------------|
| 1      | 5                                             |
| 2      | 55, 10, 0, 25, 1                              |
| 3      | 555, 1(+-/x)2, 2(+-/x)1                       |
| 4      | 5555, 1(+-/x)3, 2(+-/x)2, 3(+-/x)1            |
| 5      | 55555, 1(+-/x)4, 2(+-/x)3, 3(+-/x)2, 4(+-/x)1 |

일반화를 한다면  

N=q이고,  
| # of N | possible numbers 								  |
|--------|----------------------------------------------------|
| n      | "q" x n, 1(+-/x)n-1, 2(+-/x)n-2, ....., n-1(+-/x)1 |


**soluiton**   
```c++
#include <unordered_set>
using namespace std;
int solution(int N, int number){
	int answer = -1;
	unordered_set<int> s[8]; //중복을 허용하지 않는 집합
	int base = 0;
	for(int i = 0; i < 8; ++i){
		base = 10 * base +1;
		s[i].insert(base*N); //5, 55, 555 ... 기본값 세팅  
	}

	for(int i = 1; i < 8; ++i){
		for(int j = 0; j < i; ++j){
			for(auto& op1: s[j]){
				for(auto& op2: s[i-j-1]){
				//j가 0 1 2...로 증가할 때 op2는 2 1 0..으로 감소
					s[i].insert(op1+op2);
					s[i].insert(op1-op2);
					s[i].insert(op1*op2);
					if(op2 != 0)
						s[i].insert(op1/op2);
				}
			}
		}
		if(s[i].count(number) > 0){ //i번째 그룹에 만들고자하는 수가 들어있다면
			answer = i + 1; //0부터 시작해서
			break;
		}
	}
	return answer;
}
```