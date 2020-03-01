#include <iostream>

int main(){
	int i = 5;
	int& j = i;  //j는 i를 참조한다. -> i의 주소를 갖는다, 가리킨다.

	std::cout << "i = " << i << " j = " << j << std::endl;

	j = 4; //j가 i의 주소를 가리키기에 j를 변경하면 i도 변경된다.

	std::cout << "i = " << i << " j = " << j << std::endl;
}