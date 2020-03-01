#include <iostream>
#include <queue>

using namespace std;

int main(){
	int test_case;
	cin >> test_case;

	for(int t = 0; t < test_case; ++t){
		queue<pair <int,int> > q;
		priority_queue<int> pq;

		int doc, key_idx;
		int cnt = 0;
		cin >> doc >> key_idx;

		for(int i = 0; i < doc; ++i){
		 	int p;
		 	cin >> p;
		 	q.push(make_pair(i,p));
		 	pq.push(p);
		}
		while(!q.empty()){
			int idx = q.front().first;
			int priority = q.front().second;
			q.pop();
			if(pq.top() == priority){ //q의 순서상 맨 앞의 값(priority)이 제일 클 때, 프린트함
				pq.pop();
				++cnt;
				if(idx == key_idx){
					cout << cnt << endl;
					break;
				}
			}else{
				q.push(make_pair(idx,priority)); //프린트 안 하는 경우 다시 뒤로 push
			}
		}
	}
}