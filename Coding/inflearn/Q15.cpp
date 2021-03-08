#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;
//에라토스테네스의 체 사용
int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int result=0,answer;
		int num;

		ifstream fin;
		fin.open(argv[j]);
		fin >> num;
		
		char arr[num+1];
		clock_t start = clock();

		for(int i = 0; i < num+1; ++i){
			arr[i] = 1;
		}

		for(int i = 2; i < num+1; ++i){
			if(arr[i] == 1){
            	if((unsigned int)pow(i,2) > 200001){ //문제 N의 조건
                	break;
            	}
            	else{
                	for(int j = (int)pow(i,2); j < num+1; ){ //소수(i)의 배수들은
                    	arr[j] = 0; //소수가 아니다
                    	j = j + i;
                	}
            	}
        	}
		}
		for(int i = 2; i < num+1; ++i){
        	if(arr[i] == 1)
            	result++;
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