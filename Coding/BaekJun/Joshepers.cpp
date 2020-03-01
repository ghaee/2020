#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, key;
	cin >> n >> key;

	queue<int> q;
	for(int i = 1; i <= n; ++i){
		q.push(i);
	}
	cout <<"<";
	while(!q.empty()){
		for(int cnt = 1; cnt < key; ++cnt){
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << q.front();
		q.pop();
		if(!q.empty())
			cout << ", ";
	}
	cout <<">" <<endl;
}