#include <iostream>

using namespace std;
int IsPrime(int num){
	for(int i = 2; i <= num/2; ++i){
		if(num % i == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int m,n;
	int sum = 0;
	cin >> m >> n;
	int min = n;
	for(int i = m; i <= n; ++i){
		if(i > 1 && IsPrime(i)){
			if(i < min)
				min = i;		
			sum += i;
		}
	}
	if(sum != 0)
		cout << sum << "\n" << min << endl;
	else
		cout << "-1" << endl;
}
