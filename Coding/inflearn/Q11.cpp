#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result,answer;
		int n,num;
		int cnt = 0;

		ifstream fin;
		fin.open(argv[j]);
		fin >> n;
		
		for(int i = 1; i <= n; ++i){
			num = i;
			while(num > 0){
				num /= 10;
				cnt++;
			}
		}
		result = cnt;

		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		fout >> answer;

		cout << "case " << j << " : ";
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