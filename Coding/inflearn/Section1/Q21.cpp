#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
	for(int j = 1; j <= 5; ++j){
		int a_score=0,a_answer,b_score=0,b_answer;
		string winner, winner_answer;
		int n,cnt=0,tmp;
		int a[11],b[11];

		ifstream fin;
		fin.open(argv[j]);
		if(!fin.is_open()){
			cout << "cannot open input file " << j <<endl;
		}

		clock_t start = clock();
		for(int i = 0; i < 10; ++i){
			fin >> tmp;
			a[i]=tmp;
		}
		for(int i = 0; i < 10; ++i){
			fin >> tmp;
			b[i]=tmp;
		}
		for(int i = 0; i < 10; ++i){
			if(a[i]>b[i]){
				a_score += 3;
				cnt = 1;
			}else if(a[i] < b[i]){
				b_score += 3;
				cnt = 2;
			}else{
				a_score += 1;
				b_score += 1;
			}
		}
		if(a_score > b_score) winner = "A";
		else if(a_score == b_score){
			if(cnt == 1){winner = "A";}
			else if(cnt == 2){winner = "B";}
			else{winner = "D";}
		}else{
			winner = "B";
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
		fout >> a_answer; fout >> b_answer;
		fout >> winner_answer;
			if(a_score == a_answer && b_score == b_answer && winner == winner_answer){
				cout <<"CORRECT! "<< a_answer <<" " << b_answer <<" "<< winner_answer << endl;
			}else{
				cout << "Wrong! Try again";
				cout << " Your result is " << winner << " the answer is " << winner_answer << endl;
			}


		fin.close();
		fout.close();

	} 

	return 0;
}