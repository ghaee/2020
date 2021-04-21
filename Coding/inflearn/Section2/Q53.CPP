#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// k진수 변환, stack 구조
// vector rbegin(), rend()
//auto i, *i 로 접근
vector<char> result;

void  convert(int n, int k){
    while (n>0){
        if(n%k < 10){ //0~9
            result.push_back(n%k + 48);
        }else{ //A~F
            result.push_back(n%k + 55);
        }
        n /= k;
    }
}
int main(int argc, char** argv){
    int n, k;
    cin >> n >> k;

    convert(n,k);
    for(auto i = result.rbegin(); i != result.rend(); ++i){
        cout << *i;
    }
    //system("PAUSE");
    return 0;
}