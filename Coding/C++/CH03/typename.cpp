#include <iostream>
using namespace std;

template<typename T>

T Mymax(T a, T b){
	if(a > b)
		return a;
	else
		return b;
}
/*
******* c 라이브러리에 있는 max와 헷갈려서 컴파일 실패 -> 이름 바꿔서 성공

*/

int main(){

	cout << "The maximum of 3 and 5 is " << Mymax(3,5) << '\n';
	cout << "The maximum of 3 and 5 is " << Mymax(3l,5l) << '\n';
	cout << "The maximum of 3.0 and 5.0 is " << Mymax(3.0,5.0)<<'\n';


	unsigned u1 = 2, u2 = 8;
	cout << "The maximum of u1 and u2 is "<< Mymax(u1,u2) <<'\n';
	cout << "The maximum of u1*u2 and u1+u2 is "<< Mymax(u1*u2,u1+u2) <<'\n';

	return 0;
}