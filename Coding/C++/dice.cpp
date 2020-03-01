#include <iostream>
#include "randomize.cpp"
int main(){
	using namespace std;
	randomize();

	cout <<"Now we roll dice:\n";
	for(int i = 0; i < 15; ++i)
		cout<<pick(1,6)<<endl;
}
