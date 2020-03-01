#include <iostream>

/*
	* 연산은 주소를 통해 "값에 접근"
	& 연산은 주소를 반환!!!
*/

int main(){
	
	//1.
	/*
		하나의 문자를 가리키는 포인터
	*/
	char a = 'A';
	char *char_ptr = &a;

	std::cout << "a: " << a << " char_ptr: " << *char_ptr << "\n";
	
	/*
		10개의 정수 요소를 갖는 배열
	*/
	int x[10] = {0,1,2,3,4,5,6,7,8,9};

	/*
		10개의 정수 요소를 갖는 배열을 가리키는 포인터 (배열 포인터)
		배열 포인터의 각 인덱스에 접근하려면 (*ptr)[index]의 형태로!!!
	*/
	int (*arr_ptr)[10];
	arr_ptr = &x;
	// std::cout << " &arr_ptr = " << &arr_ptr << "\n";
	// std::cout << " arr_ptr = " << arr_ptr << "\n";

	for(int j = 0; j < 10 ; ++j){
		//값 확인
		std::cout << "x[" << j << "] = " << x[j] <<" | ";
		std::cout << "(*arr_ptr)[" << j << "] = " << (*arr_ptr)[j] << "\n";
		/*  주소 확인
		std::cout << "&x[" << j << "] = " << &x[j] <<" | ";
		std::cout << " &(*arr_ptr)[" << j << "] = " << &(*arr_ptr)[j] << "\n";
		*/
	}

	/*
		문자로 이루어진 배열을 가리키는 포인터
		배열 끝에 "\0"이 들어가있어 자동으로 줄바꿈이 된다....?
	*/
	char tmp[4] = {'a','b','c','d'};
	char (*tmp_ptr)[4];
	tmp_ptr = &tmp;
	std::cout << " *tmp_ptr = " << *tmp_ptr;
	for(int j = 0; j < 4 ; ++j){
		//값 확인
		std::cout << "tmp[" << j << "] = " << tmp[j] << " | ";
		std::cout << "(*tmp_ptr)[" << j << "] = " << (*tmp_ptr)[j] << "\n";
		/* 주소 확인
		std::cout << "&tmp[" << j << "] = " << &tmp[j];
		std::cout << " &(*tmp_ptr)[" << j << "] = " << &(*tmp_ptr)[j];
		*/
	}

	
	/*
		"문자를 가리키는 포인터"를 가리키는 포인터
	*/
	char **ptr_ptr = &char_ptr;

	std::cout << "**ptr_ptr: " << **ptr_ptr << "\n";

	
	/*
		정숫값을 갖는 상수
	*/
	const int i = 1;


	/*
		정수값을 갖는 '상수를 가리키는 포인터'
	*/
	const int j = 2; //상수 j
	const int *int_ptr = &j;  //--> j의 값을 바꿀 수 없어, 단 *i_ptr = &k 는 가능

	std::cout << "*int_ptr (j=2): " << *int_ptr << " --> ";
	const int k = 3; //상수 k
	int_ptr = &k;
	std::cout << "*int_ptr (k=3): " << *int_ptr <<"\n";

	//j = 3; //오류

	/*
		정수를 가리키는 '상수 포인터'
	*/
	int num = 100;
	int * const const_ptr = &num; //--> const_ptr이 가리키는 주소를 바꿀 수는 없어(포인터가 상수임), 단 num = 101은 가능
	std::cout << "const_ptr (num=100): " << *const_ptr << " --> ";
	num = 101; 
	std::cout << "const_ptr (num=101): " << *const_ptr << "\n";

	//const_ptr = &i; //오류


}
