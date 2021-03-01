
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char** argv){

	for(int j = 1; j <= 5; ++j){
		int n, i, a;
		int min = 2147000000, max = -2147000000; //int형의 가장 작은 값
		int result, answer;

		ifstream fin;
		fin.open(argv[j]);
		fin >> n;
		
		for(i = 0; i < n; ++i){
			fin >> a;
			if(a <= min){
				min = a;
			}
			if(a >= max){
				max = a;
			}
		}
		result = max - min;

		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str();
		ifstream fout;
		fout.open(filename);
		fout >> answer;

		cout << argv[j] << " "<< filename << endl;
		if(result == answer){
			cout <<"CORRECT! the answer is " << answer << endl;
		}else{
			cout << "Wrong! Try again" << endl;
			cout << "Your result is " << result << " the answer is " << answer << endl;
		}
		fin.close();
		fout.close();

	}
	return 0;
}