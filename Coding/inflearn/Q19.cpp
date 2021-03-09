#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result,answer;
		int n,max,cnt=0,tmp;
		int arr[101]={0,};

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}
		fin >> n;

		clock_t start = clock();
		for(int i = 0; i < n; ++i){
			fin >> tmp;
			arr[i]=tmp;
		}

		max = arr[n-1];
		for(int i = n-2; i >= 0; --i){
			if(arr[i] > max){
				max = arr[i];
				cnt++;
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