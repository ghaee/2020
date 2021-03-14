#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int digit_sum(int x){
	int tmp, sum=0;
	while(x>0){
		tmp = x%10; //일의 자리만 남김
		sum += tmp;
		x /= 10; //일의 자리 지움 그 다음 백,천의 자리로..
	}
	return sum;
}
int main(int argc, char** argv){

	for(int j = 1; j <= 5; ++j){
		int result,answer;
		int n,num, max = -2147000000;
		int sum = 0;

		ifstream fin;
		fin.open(argv[j]);
		fin >> n;
		
		for(int i = 0; i < n; ++i){
			fin >> num;
			sum = digit_sum(num);
			if(sum > max){
				max = sum;
				result = num;
			}else if(sum == max){
				if(num > result)
					result = num;

			}
		}


		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		fout >> answer;

		cout << "case " << j << " : ";
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

