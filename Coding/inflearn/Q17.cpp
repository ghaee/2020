#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		string result="YES",answer;
		int n,sum=0,num,tmp;

		ifstream fin;
		fin.open(argv[j]);
		fin >> n;

		string file = "out" + to_string(j) + ".txt";
		const char * filename = file.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		clock_t start = clock();
		for(int i = 0; i < n; ++i){
			fin >> num; fin >> sum;
			tmp = 0;
			for(int x = 1; x <= num; ++x){
				tmp +=x;
			}
			if(tmp == sum){
				result = "YES";
			}else{
				result = "NO";
			}
			fout >> answer;
			if(result == answer){
				cout <<"CORRECT! "<<" the answer is " << answer << endl;
			}else{
				cout << "Wrong! Try again";
				cout << " Your result is " << result << " the answer is " << answer << endl;
			}
		}
		clock_t end = clock();
		double time = (double)(end - start)/CLOCKS_PER_SEC;
		cout << "case " << j <<  " | Time: " << time  <<" s"<<endl;

		fin.close();
		fout.close();

	} 

	return 0;
}