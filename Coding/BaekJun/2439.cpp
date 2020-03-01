#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int i,j,n;
	cin >> n;
	for(i = 0; i < n; ++i){
		for(int k = 1; k < n-i ; ++k)
			cout <<k;
		for(j = 0; j <= i; ++j){
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}