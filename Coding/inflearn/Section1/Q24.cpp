#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		string result="YES",answer;
		int n,pre,now,tmp;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}
		fin >> n;
		vector<int> v(n); //선언하면서 0으로 초기화
		fin >> pre;
		clock_t start = clock();
		for(int i = 1; i < n; ++i){
			fin >> now;
			tmp = abs(now - pre);
			if(tmp > 0 && tmp < n && v[tmp] == 0){ // abs값이 1~n-1까지의 값인지, 이전에 체크되지 않았는지 확인 
				v[tmp] = 1;
			}else{
				result = "NO"; 
				break;
			}
			pre = now;
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
				cout << "Wrong! Try again";
				cout << " Your result is " << result << " the answer is " << answer << endl;
			}


		fin.close();
		fout.close();

	} 

	return 0;
}