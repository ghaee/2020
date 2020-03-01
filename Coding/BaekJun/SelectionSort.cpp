#include <iostream>

using namespace std;

int main(){
	int cnt;
	int tmp;
	cin >> cnt;
	int *num = new int[cnt+1];
	cin >> num[0];
	for(int i=1; i<cnt; ++i){
		cin >> num[i];
		for(int j = 0; j < i; ++j){
			if(num[i] < num[j]){
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}

	for(int i = 0; i < cnt; ++i){
		cout << num[i] <<endl;
	}
}
