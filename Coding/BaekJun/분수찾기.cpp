#include <iostream>

using namespace std;

int main(){
	int key;
	cin >> key;

	int level = 0;
	int bound = 0;
	int i = 1;
	while(true){
		bound += level;
		if(key <= bound){
			break;
		}
		++level;
	}
	int cnt = bound - level + 1;

	if(level % 2 == 0) //if level is even -> Descending order
	{ //(1,level) ~ (level,1)
		int *arr = new int[level+1];
		while(true){
			arr[i] = cnt++;
			if(arr[i] == key)
				break;
			--level;
			++i;
		}
		cout <<i<<"/"<< level <<endl;
	}
	else{ // odd -> Ascending order
		//(level,1) ~ (1,level)
		int *arr = new int[level+1];
		while(true){
			arr[level] = cnt++;
			if(arr[level] == key){
				break;
			}
			--level;
			++i;

		}
		delete[] arr;
		cout <<level<<"/"<< i <<endl;
	}

}
