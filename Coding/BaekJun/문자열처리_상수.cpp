#include <iostream>
#include <string>
using namespace std;

int main(){
	int a, b;

	cin >> a >> b;

	int ra, rb;

	ra = (a % 10) * 100
			+
		 (a % 100) / 10 * 10
		 	+
		 (a / 100);

	rb = (b % 10) * 100
			+
		 (b % 100) / 10 * 10
		 	+
		 (b / 100);
	int max = (ra > rb) ? ra : rb;
	cout << max << endl;
	
}