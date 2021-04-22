#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int check[11];
int n;
void dfs(int k){
    if(k == n+1){
        for(int i = 1; i <= n; ++i){
            if(check[i] == 1){
                cout << i <<" ";
            }
        }
        cout << endl;
    } 
    else{
        check[k] = 1;
        dfs(k+1);
        check[k] = 0;
        dfs(k+1);
    }
}

int main(int argc, char** argv){
    cin >> n;
    dfs(1);
    system("PAUSE");
    return 0;
}