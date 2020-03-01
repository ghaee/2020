#include <iostream>
#include <string>
using namespace std;


int main(){
	int n;
	cin >> n;
	string s;
	int *arr = new int[n+1];
	int i = -1;
	do{
		cin >> s;
		if(s == "push"){
			int element;
			cin >> element;
			arr[++i] = element;
		}else if(s == "pop"){
			if(i < 0)
				printf("-1\n");
			else{
				printf("%d\n",arr[i]);
				--i;
			}
		}else if(s == "size"){
			printf("%d\n",i+1);
		}else if(s == "empty"){
			if(i < 0)
				printf("1\n");
			else
				printf("0\n");
		}else if(s == "top"){
			if(i < 0)
				printf("-1\n");
			else
				printf("%d\n",arr[i]);
		}
		--n;
	}while(n > 0);


}
