#include <stdio.h>

int main(){
	int tc,r;
	char input[21];
	scanf("%d",&tc);

	do{
		scanf("%d %s",&r,input);
		for(int i = 0; input[i]; ++i)
			for(int j = r; j > 0; j--)
				putchar(input[i]);
		puts("");
		tc--;
	}while(tc > 0);

	return 0;
}