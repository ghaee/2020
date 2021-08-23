#include <iostream>
using namespace std;

int n;
int maxx = -2147000000, minn = 2147000000;
int *num, *op;
void dfs(int L, int result){
	if(L == n){
        if(result > maxx) maxx = result;
        if(result < minn) minn = result;
    }else{
        if(op[0] > 0){
            op[0]--;
            dfs(L+1, result + num[L]);
            op[0]++;
        }
        if(op[1] > 0){
            op[1]--;
            dfs(L+1, result - num[L]);
            op[1]++;
        }
        if(op[2] > 0){
            op[2]--;
            dfs(L+1, result * num[L]);
            op[2]++;
        }
        if(op[3] > 0){
            op[3]--;
            dfs(L+1, result / num[L]);
            op[3]++;
        }
    }
}
int main(){
    
	cin >> n;
    num = new int[n+1];
    op = new int[n-1];
    for(int i = 0; i < n; ++i){
        cin >> num[i];
    }

    for(int i = 0; i < 4; ++i){
        cin >> op[i];
    }

	dfs(1,num[0]);
	cout << maxx << "\n" << minn << endl;
	return 0;
}