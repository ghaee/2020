#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

int reverse(int x){
	int tmp, result=0;
	while(x>0){
		tmp = x%10;
		result = result*10 + tmp;
		x /= 10;
	}
	return result;
}

bool isPrime(int x){
	if(x < 2) return false;
	for(int i=2; i<=sqrt(x); i++) {
        if((x%i)==0) {
            return false;
        }
    }
    return true;
}
int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		string result="",answer;
		int num,reversed;
		int n;
		ifstream fin;
		fin.open(argv[j]);
		fin >> n;
		
		clock_t start = clock();
		for(int i = 1; i <= n; ++i){
			fin >> num;
			reversed = reverse(num);
			if(isPrime(reversed)){
				result += to_string(reversed);
				result += ' ';
			}
		}
		result.erase(result.size()-1);
		clock_t end = clock();

		string file = "out" + to_string(j) + ".txt";
		const char * filename = file.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		getline(fout,answer);

		double time = (double)(end - start)/CLOCKS_PER_SEC;

		cout << "case " << j <<  " | Time: " << time  <<" s"<<endl;
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