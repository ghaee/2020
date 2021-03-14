#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		string form;
		int i,result, answer, a = 0, b = 0, h =0;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}
		fin >> form;
		cout << form << endl;
		//CaHb C : 12 H : 1
		clock_t start = clock();
		if(form[1] == 'H'){
			a = 1;
			h = 1;

		}else{
			for(i = 1; form[i] != 'H'; ++i){
				a = a*10 +  (form[i]-48);
			}
			h = i;
		}
		if(form[h+1] == '\0'){
			b = 1;
		}else{
			for(i = h+1; form[i] != '\0'; ++i){
				b = b*10 +  (form[i]-48);
			}
		}
		result = a*12 + b;
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