#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    int n, a=1,cnt=0,tmp,i;
    
    scanf("%d",&n);

    tmp = n; //정답 출력용

    n--;
    while(n > 0){
        a++; 
        /*
        if (a == 2) -> 두개의 연속된 수로 만들 수 있는지 확인
        a == 3 -> 세 개의 연속된 수로 만들 수 있는지 확인
        */
        n -= a;
        if(n%a == 0){
            for( i = 1; i < a; ++i){
                printf("%d + ", n/a+i);
            }
            printf("%d = %d\n", n/a+i,tmp);
            cnt++;
        }
    }
    printf("%d\n",cnt);
    
	return 0;
}