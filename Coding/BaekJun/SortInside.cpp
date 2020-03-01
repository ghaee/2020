#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	getline(cin,input);

	sort(input.begin(),input.end(),greater<int>());

	cout << input;	
}
