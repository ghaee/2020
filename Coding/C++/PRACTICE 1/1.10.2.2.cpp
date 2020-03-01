#include <iostream>


int main(){

	//스택(고정 크기 배열)
	int x[20];
	for(int i = 0; i < 20; ++i){
		x[i] = i;
		std::cout << "x[" << i <<"] : " << x[i] << " ";
		if((i+1)%5 == 0) std::cout << "\n";
	}
	std::cout << "\n";
	//힙(동적 할당 배열)
	std::cout <<"배열의 크기를 입력하세요: ";
	int size;
	std::cin >> size;
	int *y = new int[size];
	std::cout << "sizeof(y): " << sizeof(y) <<"\n";
	for(int i = 0; i < size; ++i){
		y[i] = i;
		std::cout << "y[" << i <<"] : " << y[i] << " ";
		if((i+1)%5 == 0) std::cout << "\n";
	}
	std::cout << "\n";

	delete[] y;
	return 0;
}