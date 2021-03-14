#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
/* 
일의 자리 수 : 9개  --> 숫자의 총 개수 1 * 9
십의 자리 수 : 900개 --> 숫자의 총 개수 2 * 90
백의 자리 수 : 900개 --> 숫자의 총 개수 3 * 900
천의 자리 수 : 9000개 --> 숫자의 총 개수 4 * 9000

위의 규칙을 이용함
*/
int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result=0,answer;
		int n,num=1,d=9;
		//num 자릿수(한자리,두자리,세자리)
		//d 등차 9, 90, 900...
		//n 입력값
		int cnt = 0;

		ifstream fin;
		fin.open(argv[j]);
		fin >> n;
		
		clock_t start = clock();

		while(cnt+d<n){ //자릿수 판별 9, 99, 999, 9999보다 큰지 작은지
			result += num*d;
			cnt += d;
			num++;
			d *= 10; //9 -> 90 -> 900...
		}
		result += (n-cnt)*num; //남은 수의 자릿수를 곱함
		clock_t end = clock();

		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		fout >> answer;

		double time = (double)(end - start)/CLOCKS_PER_SEC;

		cout << "case " << j <<  " Time: " << time <<endl;
		if(result == answer){
			cout <<"CORRECT! "<<" the answer is " << answer << endl;
		}else{
			cout << "Wrong! Try again" << endl;
			cout << "Your result is " << result << " the answer is " << answer << endl;
		}
 
		fin.close();
		fout.close();

	}
}