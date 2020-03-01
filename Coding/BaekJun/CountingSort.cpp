#include <iostream>

using namespace std;


int main(){
	int n;
	int input;
	int cnt;
	cin >> n;

	int num[10001] = {0};
	for(int i = 0; i < n; ++i){
		scanf("%d",&input);
		num[input] += 1;
	}

	for(int i = 1; i <= 10000; ++i){
		cnt = num[i];
		for(int j = 0; cnt != 0 && j < cnt; ++j){
			printf("%d\n",i);
		}
	}
}
