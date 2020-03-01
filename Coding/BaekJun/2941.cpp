#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	//char[] alphabet = {'c=','c-','dz=','d-','lj','nj','s=','z='};
	int cnt=0;
	getline(cin,input);
ㄴ
	for(int i = 0; i < input.length(); ++i){ //조건절 안에서 ++i하면서 크로아티아 알파벳을 하나의 알파벳으로 취급하게끔
		//cout << "for i:" << i <<endl;
		if(input[i] == 'c'){
			if(input[i+1] == '=' || input[i+1] == '-')
				++i;
			//cout << "c -> i:" << i <<endl;
		}
		if(input[i] == 'd'){
			if(input[i+1] == 'z' && input[i+2] == '='){
				++i;
				++i;
			}
			if(input[i+1] == '-')
				++i;
			//cout << "d -> i:" << i <<endl;
		}
		if(input[i] == 'l'){
			if(input[i+1] == 'j')
				++i;
			//cout << "l -> i:" << i <<endl;
		}
		if(input[i] == 'n'){
			if(input[i+1] == 'j')
				++i;
			//cout << "n -> i:" << i <<endl;
		}
		if(input[i] == 's'){
			if(input[i+1] == '=')
				++i;
			//cout << "s -> i:" << i <<endl;
		}
		if(input[i] == 'z'){
			if(input[i+1] == '=')
				++i;
			//cout << "z -> i:" << i <<endl;
		}
		++cnt; //크로아티아 알파벳을 카운팅함
	}
	cout << cnt <<endl;
}