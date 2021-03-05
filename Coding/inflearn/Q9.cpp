#include <iostream>
#include <string>
#include <fstream>

/*
 거의 nlog(n)에 가까운 시간복잡도
*/
using namespace std;
int main(int argc, char** argv){

	for(int j = 1; j <= 5; ++j){
		string result="";
		string answer;
		int num;
		int cnt[50001] = {0,};

		ifstream fin;
		fin.open(argv[j]);
		fin >> num;
		
		for(int i = 1; i <= num; ++i){ //알고리즘
			for(int j = i; j <= num; j+=i){ //i의 배수로 loop
				cnt[j]++;
			}
		}

		for(int i = 1; i < num; ++i){ //정답 형식 맞추기
			result.append(to_string(cnt[i]));
			result.push_back(' ');
		}
		result += to_string(cnt[num]);

		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		getline(fout,answer);

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