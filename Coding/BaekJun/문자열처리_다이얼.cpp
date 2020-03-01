#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string input;
	int num[15];
	int t =0;
	getline(cin,input);

	for(int i = 0; i < input.length(); ++i){
		if(input[i] <= 67)
			num[i] = 2;
		else if(input[i] <= 70)
			num[i] = 3;
		else if(input[i] <= 73)
			num[i] = 4;
		else if(input[i] <= 76)
			num[i] = 5;
		else if(input[i] <= 79)
			num[i] = 6;
		else if(input[i] <= 83)
			num[i] = 7;
		else if(input[i] <= 86)
			num[i] = 8;
		else if(input[i] <= 90)
			num[i] = 9;
		t += num[i]+1;
	}
	
	cout << t << endl;
	return 0;
}
