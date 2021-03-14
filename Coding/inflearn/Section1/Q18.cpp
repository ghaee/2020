#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result,answer;
		int n,m,cnt=0,val,max=-2147000000;

		ifstream fin;
		fin.open(argv[j]);
		fin >> n;
		fin >> m;

		clock_t start = clock();
		for(int i = 0; i < n; ++i){ 
			fin >> val;
			if(val > m){
				cnt++;
			}else{
				cnt = 0;
			}
			if(cnt >= max){
				max = cnt;
			}
		}
		if(max == 0){ 
			result = -1;
		}else{
			result = max;
		}
		clock_t end = clock();

		double time = (double)(end - start)/CLOCKS_PER_SEC;

		string file = "out" + to_string(j) + ".txt";
		const char * filename = file.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		cout << "case " << j <<  " | Time: " << time  <<" s"<<endl;
		fout >> answer;
			if(result == answer){
				cout <<"CORRECT! "<<" the answer is " << answer << endl;
			}else{
				cout << "Wrong! Try again";
				cout << " Your result is " << result << " the answer is " << answer << endl;
			}

		fin.close();
		fout.close();

	} 

	return 0;
}