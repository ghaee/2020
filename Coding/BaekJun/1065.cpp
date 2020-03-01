#include <iostream>
using namespace std;

int HANSU(int n){
	int i = 1;
	int a,b,c;
	int result;
	int cnt = 0;
	for(i;i <= n; ++i){
		if(i < 100) cnt = i;
		if(i == 1000) break;
		else{
			a= i / 100;
			b= i % 100 / 10;
			c= i % 10;
			if(a-b == b-c){
				cnt++;
			}
		}
	}
	result = cnt;
	return result;
}

int main(){
	int n;
	cin >> n;

	cout << HANSU(n) << endl;

}