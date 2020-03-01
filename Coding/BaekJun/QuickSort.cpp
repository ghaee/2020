#include <iostream>

using namespace std;
int *num;
void QuickSort(int *num,int start,int end){
	int i=start,j=end,tmp;
	int x = num[start]; // pivot

	if(start < end){ //# of elements >= 2
		while(i<=j){
			while(num[i] < x && i < j)
				++i;
			while(num[j] >= x && i < j){
				--j;
			}
			if(i < j){ //swap
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}else{
				break;
			}
		}
		//recursive call
		QuickSort(num,start,j-1);
		QuickSort(num,j+1,end); 
	}
}
int main(){
	int n;
	cin >> n;
	
	num = new int[n+1];
	for(int i = 0; i < n; ++i){
		cin >> num[i];
	}

	QuickSort(num,0,n-1);
	for(int i = 0; i < n; ++i){
		cout << num[i] << endl;
	}
}
