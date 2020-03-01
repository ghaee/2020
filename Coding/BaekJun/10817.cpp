#include <iostream>
using namespace std;

int main(){
	int a, b, c;

	cin >> a >> b >> c;

	if(a >= b && a >= c){
		if(b >= c)
			cout << b;
		else
			cout << c;
		return 0;
	}

	if(b >= c && b >= a){
		if(a >= c)
			cout << a;
		else
			cout << c;
		return 0;
	}

	if(c >= a && c >= b){
		if(a >= b)
			cout << a;
		else
			cout << b;
		return 0;
	}
}