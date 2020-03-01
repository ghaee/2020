#include <iostream>
#include <string>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int result = a * b * c;
	int tmp;
	int arr[10] = {0}; //result에 쓰인 숫자의 개수를 저장할 배열

	do{
		tmp = result % 10;
		switch(tmp){
			case 0:
				arr[0] += 1;
				break;
			case 1:
				arr[1] += 1;
				break;
			case 2:
				arr[2] += 1;
				break;
			case 3:
				arr[3] += 1;
				break;
			case 4:
				arr[4] += 1;
				break;
			case 5:
				arr[5] += 1;
				break;
			case 6: 
				arr[6] += 1;
				break;
			case 7:
				arr[7] += 1;
				break;
			case 8:
				arr[8] += 1;
				break;
			case 9:
				arr[9] += 1;
				break;
		}
		result /= 10;
	}while(result != 0);

	for(int i = 0 ;i < 10; ++i)
		cout << arr[i] << endl;
}