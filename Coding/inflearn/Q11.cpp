#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result,answer;
		int n,num;
		int cnt = 0;

		ifstream fin;
		fin.open(argv[j]);
		fin >> n;
		
		clock_t start = clock();

		for(int i = 1; i <= n; ++i){
			num = i;
			while(num > 0){
				num /= 10;
				cnt++;
			}
		}
		result = cnt;

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