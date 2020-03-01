#include <iostream>
#include <string>
using namespace std;

int main(){
	int cnt = 0;
	string sentecne = {};
	getline(cin,sentecne);

	for(int i = 0; i < sentecne.length();++i){
		if(sentecne.at(i) == ' ')
			cnt++;
	}
	if(sentecne.at(0) == ' ') //처음부터 공백일 경우
		cnt--;
	if(sentecne.at(sentecne.length()-1)==' ') //문장 끝에 공백이 있을 경우
		cnt--;
	cout << cnt+1 << endl;
}