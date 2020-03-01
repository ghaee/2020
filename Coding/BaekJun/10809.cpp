#include <iostream>
#include <string>
using namespace std;

int main(){
	string word = {};
	int pos = 0;
	char c[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	getline(cin,word);

	for(int i = 0; i < 26; ++i){
		pos = word.find(c[i],0);
		if(pos == string::npos)
			cout << "-1" << " ";
		else
			cout << pos << " ";
	}
	cout << "\n";
}