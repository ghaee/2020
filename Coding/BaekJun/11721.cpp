#include <iostream>
#include <string>
using namespace std;

int main(){
	string word;
	cin >> word;
	for(int i = 0; i < word.length() ; ++i){
		cout << word[i];
		if((i+1)%10 == 0) //0부터 카운트 하니까
			cout << "\n";
	}

	return 0;
}