#include <iostream>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	int a=0,b=0;
	for(int i = 1; i <= t; ++i){
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}
	
	return 0;
}
