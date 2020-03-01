#include <iostream>
using namespace std;

int main(){
	int c,n;
	scanf("%d\n",&c);

	while(c){
		scanf("%d",&n);
		int score[n];
		int sum = 0;
		double ave;
		for(int i = 0; i < n; ++i){
			scanf("%d",&score[i]);
			sum += score[i];
		}
		ave = (double)sum/n;
		int count = 0;
		for(int i = 0; i < n;++i){
			if(score[i] > ave)
				count++;
		}
		printf("%.3f",(double)count*100/n);
		printf("%%\n");
		c--;
	}
}