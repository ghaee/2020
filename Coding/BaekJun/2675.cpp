#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int tc,r;

	cin >> tc;
	
	do{	
		string input = "";
		string result = "";
		cin >> r >> input;
		for(int i = 0; i < input.length();++i){
			for(int j = 0; j < r; ++j){
				result += input[i];
			}
		}
		cout << result << endl;
		tc--;
	}while(tc > 0);
	
}