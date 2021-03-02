
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char** argv){

	for(int j = 1; j <= 5; ++j){
		int result = 0, cnt = 1; //약수의 개수는 최소 1개부터 시작
		int num_answer, cnt_answer;
		char a[100];

		ifstream fin;
		fin.open(argv[j]);
		fin >> a;

		for(int i = 0; a[i] != '\0'; ++i){
			if(a[i] >= 48 && a[i] <= 57){ //숫자 0~9 (ASCII 48~57)
				result = result*10+(a[i]-48);
			}
		}

		for(int i = 1; i < result; ++i){
			if(result%i==0){
				++cnt;
			}
		}

		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		fout >> num_answer;
		fout >> cnt_answer;

		cout << "case " << j << " : ";
		if(result == num_answer && cnt == cnt_answer){
			cout <<"CORRECT! the answer is " << num_answer <<" " << cnt_answer<< endl;
		}else{
			cout << "Wrong! Try again" << endl;
			cout << "Your result is " << result << " " << cnt << " the answer is " << num_answer <<" " << cnt_answer<< endl;
		}
		fin.close();
		fout.close();

	}
	return 0;
}