#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){

	for(int j = 1; j <= 5; ++j){
		string result="";
		string answer;

		ifstream fin;
		fin.open(argv[j]);
		getline(fin,result); //getline은 string으로 받아야함!
		
		result.erase(remove(result.begin(), result.end(), ' '), result.end()); //공백제거 및 길이 줄이기
		transform(result.begin(),result.end(),result.begin(),::tolower); //대 -> 소 변환

		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		fout >> answer;

		cout << "case " << j << " : ";
		if(result == answer ){
			cout <<"CORRECT! the answer is " << answer << endl;
		}else{
			cout << "Wrong! Try again" << endl;
			cout << "Your result is " << result << " the answer is " << answer << endl;
		}
		fin.close();
		fout.close();

	}
	return 0;
}