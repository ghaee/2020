#include <iostream>
#include <string>
using namespace std;

int main(){
	string input;
	getline(cin, input);

	int alphabet[26] = {0}; //A~Z, 이 배열에 각 알파벳이 몇 번 나왔는지 카운트할거임

	int size = input.size();
	int max = 0;
	char answer;

	for(int i = 0; i <= size; ++i){ //대,소문자 모두 같은 알파벳으로 카운팅
		if(input[i] >= 65 && input[i] <= 90) //upper class
			alphabet[input[i]-65] += 1;
		if(input[i] >= 97 && input[i] <= 122) //lower class
			alphabet[input[i]-97] += 1;
	}

	for(int j = 0; j < 26; ++j){ //카운트끼리 비교하면서 max 찾기
		if(alphabet[j] > max){
			answer = j + 65; //return to upper class
			max = alphabet[j];
		}
		else if(alphabet[j] == max){ // 카운트 같은게 2개 이상이면 '?' 출력
			answer = '?'; // "?" 아니고 '?'임. char 형
		}
	}
	cout << answer << endl;
}
