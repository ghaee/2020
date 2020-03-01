#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	int cnt;
	char arr[51] = {'\0',};
	
	cin >> t;
	for(int i = 0; i < t; ++i){
		scanf("%s",arr);
		cnt = 0;
		for(int j = 0; arr[j] != '\0'; ++j){
			if(arr[j] == '(')
				++cnt;
			else if(arr[j] == ')'){
				--cnt;
			}
			if(cnt < 0)
				break;
		}
		if(cnt == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}