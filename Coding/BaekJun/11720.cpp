#include <iostream>
using namespace std;

int main(){
	int cnt;
	cin >> cnt;

	char* num = new char[cnt];
	cin >> num;
	int sum = 0;
	for(int i = 0; i < cnt; ++i){
		sum += num[i] - '0'; //ascii --> int
	}

	cout << sum << endl;
	return 0;
}