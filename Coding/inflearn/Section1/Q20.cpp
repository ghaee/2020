#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		string result,answer;
		int n,max,cnt=0,tmp;
		int a[101],b[101];

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}

		string file = "out" + to_string(j) + ".txt";
		const char * filename = file.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		if(!fout.is_open()){
			cout << "cannot open output file " << j <<endl;
		}

		fin >> n;

		clock_t start = clock();
		for(int i = 0; i < n; ++i){
			fin >> tmp;
			a[i]=tmp;
		}
		for(int i = 0; i < n; ++i){
			fin >> tmp;
			b[i]=tmp;
		}
		for(int i = 0; i < n; ++i){
			if(a[i]==b[i]){
				result = "D";
			}else if(a[i] == 1 && b[i] == 3){ result = "A"; }
			else if(a[i] == 2 && b[i] == 1){ result = "A"; }
			else if(a[i] == 3 && b[i] == 2){ result = "A"; }
			else{ result = "B"; }
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
		cout << "-------case " << j <<  " | Time: " << time  <<" s---------"<<endl;

		fin.close();
		fout.close();

	} 

	return 0;
}