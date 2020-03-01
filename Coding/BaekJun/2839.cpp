#include <iostream>
#include <string>
using namespace std;

int main(){
	auto n = 0;
	cin >> n;

	int only5 = n/5;
	while(only5 >= 0){ //0이면 5kg = 0개 나머지를 3kg 봉지로
		int remain = n - (only5*5); //전체 n에서 5kg 봉지로 채운 양(only5*5)을 제외
		if(remain % 3 == 0){ //나머지 양이 3kg 봉지로 나눠 떨어지면
			cout << only5 + (remain/3) << endl; // 5kg 봉지 수 + 3kg 봉지 수
			break;
		}
		only5--; //3kg 봉지로 나눠 떨어지지 않으면 5kg 봉지 수를 줄여가면서 3kg 봉지를 맞춰감
	}
	if(only5 < 0) //반복문을 마쳤는데도 답이 없다면
		cout << -1 << endl;
	return 0;
}