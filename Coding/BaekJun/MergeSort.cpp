#include <iostream>

using namespace std;
void MergeSort(int num[], int start, int end);
void Merge(int num[],int start, int mid, int end);

int *num;
int *tmp;
int main(){
	int cnt;
	cin >> cnt;

	num = new int[cnt+1];
	tmp = new int[cnt+1];

	for(int i = 0; i < cnt; ++i){
		scanf("%d",&num[i]);
	}
	MergeSort(num,0,cnt-1);

	for(int i = 0; i < cnt; ++i){
		printf("%d\n",num[i]);
	}

}

void MergeSort(int num[], int start, int end){
	int mid;
	if(start < end){ 
		mid = (start+end)/2;

		MergeSort(num,start,mid);
		MergeSort(num,mid+1,end);
		Merge(num,start,mid,end);
	}
}

void Merge(int num[], int start, int mid, int end){
	int h = start; // (start~mid)
	int i = start; //tmp index
	int j = mid + 1; //(mid+1~end)
	int k; //for index
	while(h <= mid && j <= end){
		if(num[h] <= num[j]){
			tmp[i] = num[h];
			++h;
		}
		else{
			tmp[i] = num[j];
			++j;
		}
		++i;
	}

	if(h > mid){
		for(k=j;k<=end;++k){
			tmp[i] = num[k];
			++i;
		}
	}else{
		for(k=h;k<=mid;++k){
			tmp[i]=num[k];
			++i;
		}
	}
	for(k=start;k<=end;++k){
		num[k] = tmp[k];
	}
}
