#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

// Selection Sort 응용이지만
// STL 활용

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int cnt=0,n,result, answer;

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}
		fin >> n;
		
		vector<int> v(n);

		clock_t start = clock();
		for(int i = 0; i < n; ++i){
			fin >> v[i];
		}

		sort(v.begin(),v.end(),greater<int> ()); //내림차순

		for(int i = 1; i < n; ++i){
			if(v[i] != v[i-1]) cnt++;
			if(cnt == 2){ //앞에 2등 있고 지금 3등 자리일 때
				/* cnt == 3 , result = v[i-1]과 같은 결과지만 반복문 연산횟수를 줄이기 위해서
					cnt == 2, result = v[i]를 채택함
				*/
				result = v[i];
				break;
			}
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