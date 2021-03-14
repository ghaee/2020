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
		int tmp,n,s,a,pos;
		string result="", answer;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}

		fin >> s;
		fin >> n;

		vector<int> cache(s);

		clock_t start = clock();
		for(int i = 0; i < n; ++i){
			fin >> a;
			pos = -1;
			for(int j = 0; j < s; ++j){
				if(cache[j] == a){ //HIT or MISS
					pos = j;
				}
			}
			if(pos == -1){ //case : MISS
				for(int j = s-1; j >= 0; --j){
					cache[j] = cache[j-1];
				}	
			}else{ //case : HIT
				for(int j = pos; j >= 0; --j){
					cache[j] = cache[j-1];
				}
			}
			cache[0] = a;
		}

		for(int i = 0; i < s; ++i){
			result += to_string(cache[i]);
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