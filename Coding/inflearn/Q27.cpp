#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		string result,answer;
		int n,tmp,x;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}
		fin >> n;
		vector<int> v(n+1);

		clock_t start = clock();
		for(int i = 2; i <= n; ++i){
			tmp = i;
			x = 2;
			while(tmp!=1){
				if(tmp%x==0){
					tmp /= x;
					v[x]++;
				}else{
					x++;
				}
			}
		}
		result = to_string(n)+"! = ";
		for(int i = 2; i <= n; ++i){
			if(v[i]!=0){
				result += to_string(v[i]) + " ";
			}
		}
		clock_t end = clock();
		result.erase(result.size()-1); //case 1~2에는 있어야하고 3~5에는 없어야함 
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
				cout <<"CORRECT! " <<endl;//<<" the answer is " << answer << endl;
			}else{
				cout << "Wrong! Try again"<<endl;
				//cout << " Your result is " << result << " the answer is " << answer << endl;
			}


		fin.close();
		fout.close();

	} 

	return 0;
}