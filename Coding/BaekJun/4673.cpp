/*
 반복문 줄이기(for/while)! 함수 호출 줄이기(리턴값 기억해두기)!
*/
#include <iostream>
#define MAX 10001
using namespace std;

int arr_d[MAX]={0,};
int d(int n){
	int result = n;
	
	if(n >= 10000){
		result += n / 10000;
		n %= 10000;
	}
	if(n >= 1000){
		result += n / 1000;
		n %= 1000;
	}
	if(n >= 100){
		result += n / 100;
		n %= 100;
	}
	if(n >= 10)	{
		result += n / 10;
		n %= 10;
	}
	return result+=n;
}

int main(){
	int dn;
	for(int i = 1; i <= MAX; ++i){
		dn = d(i);
		if(dn <= MAX)
			arr_d[dn] = 1;
		if(arr_d[i] == 0)
			printf("%d\n",i);
	}
}