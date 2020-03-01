#include <iostream>
using namespace std;

int main(){
	int input[9];
	int asc = 0;
	int des = 0;
	for(int i = 1; i <= 8; ++i){
		cin >> input[i];
		if(input[i] == i) //i가 오름차순으로 증가하니 index == element면 오름차순이다.
			asc++;  //오름차순으로 몇개가 있는지
		if(input[i] == 9 - i)
			des++; //내림차순으로 몇개가 있는지
	}

	if(asc == 8) cout << "ascending" << endl; //8개가 차례로 오름차순이어야 하니까
	else if(des == 8) cout << "descending" << endl; //8개가 " 내림차순 "
	else cout << "mixed" << endl;
}