#include <iostream>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	int nums[n];
	int nums2[n]; 
	int j = 0;
	for(int i = 0; i < n; ++i){
		cin >> nums[i];
		if(nums[i] < x)
			nums2[j++] = nums[i];
	}

	for(int k = 0; k < j;++k)
		cout << nums2[k] << " ";
	cout << endl;

}