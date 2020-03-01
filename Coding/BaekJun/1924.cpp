#include <iostream>
using namespace std;

int main(){
	int x, y,days = 0;
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	cin >> x >> y;

	for(int i = 0; i < x-1; ++i){
		days += month[i]; //1월~(x-1)월까지의 일수 합
	}
	days += y; //x월의 일 수까지 더하기

	switch(days%7){ //1월 1일부터 x월 y일까지의 총 일 수를 7로 나눈 나머지로 요일 결정
		//1월 1일 -> days == 1일때 MON
		case(0): printf("SUN\n");
				break;
		case(1): printf("MON\n");
				break;
		case(2): printf("TUE\n");
				break;
		case(3): printf("WED\n");
				break;
		case(4): printf("THU\n");
				break;
		case(5): printf("FRI\n");
				break;
		case(6): printf("SAT\n");
				break;
	}
	return 0;
}