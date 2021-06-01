#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> T,P;
int n, answer = -2147000000;

void dfs(int L, int sum){
	if(L == n+1){
		if(sum > answer) answer = sum;
	}else{
		if(L + T[L] <= n+1){//n+1일 차에는 무조건 휴가를 가기 때문에 넘기면 안됨
			//O L일차 상담을 하는 경우
			dfs(L + T[L], sum + P[L]);
		}
        //X 하지 않고 다음날로 넘어가는 경우
			dfs(L + 1, sum);
	}
}
int main(){
    ios_base::sync_with_stdio(false); // 입출력 속도 향상을 위해서
    int t, p;
	cin >> n;
	
    T.push_back(0); //0번 인덱스는 사용하지 않기 위해서 1일차, 2일차, 3일차,,,이렇게 갈거임
    P.push_back(0);
	for(int i = 0; i < n; ++i){
		cin >> t >> p;
		T.push_back(t);
        P.push_back(p);
	}

	dfs(1,0);
	cout << answer << endl;
	return 0;
}