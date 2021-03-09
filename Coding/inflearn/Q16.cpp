#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;
/*
ASCII 값 A~Z : 65~90 a~z : 97~122
*/
int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		string result="YES",answer;
		string str;
		int cnt1[55]={0,}, cnt2[55]={0,};

		ifstream fin;
		fin.open(argv[j]);
		getline(fin,str);
		clock_t start = clock();
		for(int i = 0; str[i] != '\0'; ++i){
			if(str[i] >= 65 && str[i] <= 90){ //Upper
				cnt1[str[i]-64]++;
			}else{//Lower
				cnt1[str[i]-70]++;
			}
		}
		getline(fin,str);
		for(int i = 0; str[i] != '\0'; ++i){
			if(str[i] >= 65 && str[i] <= 90){ //Upper
				cnt2[str[i]-64]++;
			}else{//Lower
				cnt2[str[i]-70]++;
			}
		}

		for(int i = 1; i <= 52; ++i){
			if(cnt1[i]!=cnt2[i]){
				result = "NO";
				break;
			}
		}
		clock_t end = clock();

		string file = "out" + to_string(j) + ".txt";
		const char * filename = file.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);
		
		fout >> answer;

		double time = (double)(end - start)/CLOCKS_PER_SEC;

		cout << "case " << j <<  " | Time: " << time  <<" s"<<endl;
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