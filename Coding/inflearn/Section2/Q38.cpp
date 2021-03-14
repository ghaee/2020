#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

// Insertion Sort 응용

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int tmp,n,s,cnt=0,pos;
		string result="", answer;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}

		fin >> n;

		vector<int> is(n+1); //Inversion Sequence
		vector<int> os(n+1); //Original Sequence

		clock_t start = clock();
		for(int i = 1; i <= n; ++i){
			fin >> is[i];
		}
		for(int i = n; i >= 1; --i){
			pos = i;
			for(int j = 1; j <= is[i]; ++j){
				os[pos] = os[pos+1];
				pos++;
			}
			os[pos]=i;
		}

		for(int i = 1; i <= n; ++i){
			result += to_string(os[i]);
			result += " ";
		}
		result.erase(result.size()-1);
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
		getline(fout,answer);
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