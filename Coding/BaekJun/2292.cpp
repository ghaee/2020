#include <iostream>

using namespace std;
//a(n+1) = an + bn; a1 = 1;
//bn = 6n;
//key = 1 + 6 + 6 + 6 + 6 +...

int main(){
	int key;
	int n = 0; //6*0, 6*1, 6*2....
	int bound = 1; //b1 = 1이기 때문에
	int cnt = 1; //key = 1이어도 이미 한 칸 지나고 있기때문에
	cin >> key;

	while(true){
		if(key <= bound)
			break;
		++n;
		bound += 6*n;
		++cnt;
	}
	cout << cnt << endl;
}