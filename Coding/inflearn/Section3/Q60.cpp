#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int check[11];
int n, sum=0;
string answer = "NO";
string dfs(int k, int sub_sum){
    if(sub_sum > (sum/2)) return answer;
    if(k == n+1) {
        if(sub_sum == (sum - sub_sum)){
            /*
            sum / 2를 조건으로 했을 때 int로 형변환되면서 값이 깎여나가
            sum이 홀수인 케이스를 만족시키지 못함!
            */
            answer = "YES";
            return answer;
        }
    }else{
        dfs(k+1, sub_sum+check[k]); // select as subset
        dfs(k+1, sub_sum); // exclude   
    }
    return answer;
}

int main(int argc, char** argv){
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> check[i];
        sum += check[i];
    }
    dfs(1,0);
    cout << answer << endl;
    system("PAUSE");
    return 0;
}