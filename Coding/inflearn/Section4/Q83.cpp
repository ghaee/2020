//Solving verbal arithmetic with permutaion

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int perm[10], ch[10];
int send(){
	return perm[6]*1000
		+ perm[1]*100
		+ perm[3]*10
		+ perm[0];
}

int more(){
	return perm[2]*1000
		+ perm[4]*100
		+ perm[5]*10
		+ perm[1];
}

int money(){
	return perm[2]*10000
		+ perm[4]*1000
		+ perm[3]*100
		+ perm[1]*10
		+ perm[7];
}

void dfs(int k){
	if(k == 8){
		if(send()+more() == money()){
			if(perm[2] == 0 || perm[6] == 0) return;
			// 's', 'm'이 첫 자리인데(가장 큰), 0이면 성립이 안되니까
			cout << "  " << perm[6] << " " << perm[1] << " " << perm[3] << " " << perm[0] << endl;
			cout <<"+ ";
			cout << perm[2] << " " << perm[4] << " " << perm[5] << " " << perm[1] << endl;
			cout << "------------\n";
			cout << perm[2] << " " << perm[4] << " " << perm[3] << " " << perm[1] <<" " << perm[7] << endl;
		}
	}else{
		for(int i = 0; i < 10; ++i){
			if(ch[i] == 0){
				perm[k] = i;
				ch[i] = 1;
				dfs(k+1);
				ch[i] = 0;
			}
		}
	}
}
int main(){

	dfs(0);
	system("PAUSE");
	return 0;
}