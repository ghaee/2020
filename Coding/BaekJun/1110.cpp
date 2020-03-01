#include <iostream>
using namespace std;

int main(){
	int num, a,flag;
	int count = 0;
	cin >> num;
	flag = num;
	while(true){
		count++;
		a = num/10 + num%10;
		num = (num%10)*10 + a%10;
		
		if(num == flag)
			break;
	}
	printf("%d\n",count);

}