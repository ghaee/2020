#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result,answer;
		int n,tmp,cnt=0;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}
		fin >> n;

		clock_t start = clock();
		for(int i = 1; i <= n; ++i){
			tmp = i;
			while(tmp > 0){
				if(tmp%10 == 3) cnt++;
				tmp /= 10;
			}
		}
		result = cnt;
		clock_t end = clock();
		
		double time = (double)(end - start)/CLOCKS_PER_SEC;

		string file = "out" + to_string(j) + ".txt";
		const char * filename = file.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		if(!fout.is_open()){
			cout << "cannot open output file " << j <<endl;
		}

		cout << "-------case " << j <<  " | Time: " << time  <<" s---------"<<endl;
		fout >> answer;
			if(result == answer){
				cout <<"CORRECT! " <<" the answer is " << answer << endl;
			}else{
				cout << "Wrong! Try again"<<endl;
				cout << " Your result is " << result << " the answer is " << answer << endl;
			}


		fin.close();
		fout.close();

	} 

	return 0;
}