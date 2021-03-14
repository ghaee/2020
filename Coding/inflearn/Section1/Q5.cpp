
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char** argv){

	for(int j = 1; j <= 5; ++j){
		int i, a;
		int age_result, age_answer;
		char sex_result, sex_answer;
		char id[15];

		ifstream fin;
		fin.open(argv[j]);
		fin >> id;
		
		switch(id[7]){
			case '1': //1900, M
				age_result = 2019-1900-(id[0]-48)*10-(id[1]-48)+1;
				sex_result = 'M';
				break;
			case '2'://1900, F
				age_result = 2019-1900-(id[0]-48)*10-(id[1]-48)+1;
				sex_result = 'W';
				break;
			case '3'://2000, M
				age_result = 2019-2000-(id[0]-48)*10-(id[1]-48)+1;
				sex_result = 'M';
				break;
			case '4'://2000, F
				age_result = 2019-2000-(id[0]-48)*10-(id[1]-48)+1;
				sex_result = 'W';
				break;
		}

		string tmp = "out" + to_string(j) + ".txt";
		const char * filename = tmp.c_str(); //tmp의 버퍼주소를 반환하는 c_str()
		ifstream fout;
		fout.open(filename);

		fout >> age_answer;
		fout >> sex_answer;

		cout << "case " << j << " : ";
		if(age_result == age_answer && sex_result == sex_answer){
			cout <<"CORRECT! the answer is " << age_answer <<" " << sex_answer<< endl;
		}else{
			cout << "Wrong! Try again" << endl;
			cout << "Your result is " << age_result << " " << sex_result << " the answer is " << age_answer <<" " << sex_answer<< endl;
		}
		fin.close();
		fout.close();

	}
	return 0;
}