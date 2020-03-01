#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n,sum,cnt;
	cin >> n;
	char answer[80];
	for(int i = 0; i < n; ++i){
		scanf("%s",&answer);
		cnt = 1;
		sum = 0;
		for(int j = 0; j < strlen(answer); ++j){
			if(answer[j] == 'O'){
				sum += cnt;
				cnt++;
			}
			else if(answer[j] == 'X'){
				cnt = 1;
			}
		}
		cout << sum << endl;
	}
}