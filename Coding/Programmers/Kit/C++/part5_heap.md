#### C++ Kit Part 5 : Heap / 더 맵게  

복잡도  

- 수가 하나 남을 때 까지 (n-1)회 반복  
- 각 단계마다 섞고 정렬하는 데에 리스트 길이에 비례함 O(n)
- TOTAL : O(n^2) <-- 배열 사용시 지나치게 높다.| 정렬하고 섞고 다시 알맞은 자리에 찾아서 넣고...  

최소/최대값을 빨리 찾아내는 것이 관건!  
힙(heap) --> max heap | min heap 
- Complete Binary Tree --> 배열로 구현 가능(인덱스로 parent-child node 접근 가능) \ 공간 효율 높음  
- **성질** : 최소/최대 원소를 상수 시간에 찾을 수 있다. O(1) 
- 연산 

>
힙 구성(heapify) : 하나의 원소를 삽입하는데 걸리는 시간 O(logN) * N개 반복 --> O(NlogN)
삽입(insert) : 임의의 원소를 주어진 힙 안에 삽입해도 **성질**을 유지한다.(구조를 유지한다 -> O(logN))       
삭제(remove) : 최소/최대 원소를 꺼내어 지운다.  그럼에도 **성질**을 유지한다. -> O(logN)    

- 응용

>정렬(heapsort) : 임의의 숫자들을 빈 힙에 삽입하면서(O(NlogN)) 다시 최소/최대값부터 순서대로 삭제하면서(O(NlogN)) 구현  
--> 최악의 경우 복잡도와 최상의 경우 복잡도 같은 정렬  
우선 순위 큐(priority queue) : 기본 FIFO 큐가 아닌 우선 순위에 따른 OUT  


```
priority_queue<int,vector<int>,greater<int>> q; //greater -> min heap 구현
/*<큐에 담을 데이터 타입,큐를 구현하기 위해 사용할 컨테이너,대소관계비교에 쓰일 연산>
*
* m = q.top(); //min heap q에 들어있는 최소값을 보여줌 O(1)
* q.pop(); //최소값 삭제 O(logN)
* q.push(x); //삽입 O(logN)
*/
```
**solution** O(NlogN)
```c++
#include <queue>
#include <vector>
using namespace std;
int solution(vector<int> scoville,int K){
	int answer = 0;
	priority_queue<int,vector<int>,greater<int>> q;

	//O(NlogN)
	for(auto& i : scoville){ //O(N)
		q.push(i); //O(logN)
	}

	//O(NlogN)
	while(1){ //O(N-1)
		int min1 = q.top();
		q.pop(); //O(logN)
		if(min1 >= K) break; //모든 음식의 스코빌 지수를 k이상으로 충족
		else if(q.empty()){
			answer = -1;
			break;
			//반복분 다 돌았는데 모든 음식의 스코빌 지수를 k로 맞추지 못함
		}
		int min2 = q.top();
		q.pop(); //O(logN)

		q.push(min1+min2*2); //O(logN)
		answer++;
	}

	return answer;
}
```