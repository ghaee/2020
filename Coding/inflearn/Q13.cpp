#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result,answer;
		int num,max=-2147000000;
		
		string arr;
		int cnt[10]={0,};

		ifstream fin;
		fin.open(argv[j]);
		fin >> arr;
		
		clock_t start = clock();
		for(int i = 0; arr[i] != '\0' ; ++i){
			num = arr[i]-48; //char -> int  
			cnt[num]++;
		}
		for(int i = 0; i < 10; ++i){
			if(cnt[i] > max){
				max = cnt[i];
				result = i;
			}else if(cnt[i] == max){
				if(i > result){
					result = i;
				}
			}
		}
		clock_t end = clock();

		string file = "out" + to_string(j) + ".txt";
		const char * filename = file.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		fout >> answer;

		double time = (double)(end - start);///CLOCKS_PER_SEC;

		cout << "case " << j <<  " | Time: " << time  <<" ms"<<endl;
		if(result == answer){
			cout <<"CORRECT! "<<" the answer is " << answer << endl;
		}else{
			cout << "Wrong! Try again" << endl;
			cout << "Your result is " << result << " the answer is " << answer << endl;
		}
 
		fin.close();
		fout.close();

	} 

	return 0;
}