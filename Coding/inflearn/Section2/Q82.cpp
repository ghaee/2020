#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int  cnt = 0;
int n, r;
int input[20], perm[20], ch[20];
void dfs(int k){
	if(r == k){
		for(int i = 0; i <k; ++i){
			cout << perm[i] << " ";
		}
		cnt++;
		cout << endl;
	}else{
		for(int i = 1; i <= n; ++i){
			if(ch[i] == 0){
				perm[k] = input[i];
				ch[i] = 1;
				dfs(k+1);
				ch[i] = 0;
			}
		}
	}
}
int main(){

	cin >> n >> r;
	
	for(int i = 1; i <= n; ++i){
		cin >> input[i];
	}

	dfs(0);
	cout << cnt << endl;

	system("PAUSE");
	return 0;
}