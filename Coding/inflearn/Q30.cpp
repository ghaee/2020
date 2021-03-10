#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
일의 자리, 십의 자리,,, 각 자리에서 3이 나오는 경우를 카운트

*/
int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result=0,answer;
		int n,lt=1, rt, cur, k=1;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}
		fin >> n;

		clock_t start = clock();
		while(lt!=0){
			lt=n/(k*10);
			rt=n%k;
			cur=(n/k)%10;
			if(cur>3) result += (lt+1)*k;
			else if(cur==3) result += (lt*k)+(rt+1);
			else result += (lt*k);
			k *= 10;
		}
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