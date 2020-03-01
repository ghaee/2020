#include <iostream>
using namespace std;

int main(){
	int n, max = 0;
	scanf("%d\n",&n);
	int scores[n];
	
	for(int i = 0; i < n; ++i){
		scanf("%d",&scores[i]);
		if(scores[i] > max)
			max = scores[i];
	}

	double new_scores[n];
	double new_sum = 0.0;

	for(int i = 0; i < n; ++i){
		new_scores[i] = (double)scores[i]*100/max;
		new_sum += new_scores[i];
	}
	
	cout << new_sum/n << endl;
}