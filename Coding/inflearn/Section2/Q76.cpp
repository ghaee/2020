#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mem[21][21]; //memoization

int comb(int n, int r){
    //global variables already initialized to 0
    if(mem[n][r] > 0) return mem[n][r];
    if(n == r || r == 0){
        return 1;
    }else{
        return mem[n][r] = comb(n-1,r-1) + comb(n-1,r);
    }
}
int main(int argc, char* argv){
    int n, r;
    cin >> n >> r;
    cout << comb(n,r);
    return 0;
}