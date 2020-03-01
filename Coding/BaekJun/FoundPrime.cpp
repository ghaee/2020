#include <iostream>

using namespace std;

int IsPrime(int tmp){

	for(int i = 2; i <= tmp/2; ++i){
		if(tmp % i == 0)
			return 0;
	}
	return 1;
}

int main(){

	int tmp,n,cnt=0;
	cin >> n;
	

	for(int i = 0; i < n; ++i){
		scanf("%d",&tmp);
		if(tmp > 1 && IsPrime(tmp)){
			++cnt;
		}

	}
	cout << cnt << endl;
}
