#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void PrintNum(int n){
    if(n == 0) return;
    else{
        PrintNum(n-1);
        cout << n;
    }
}

int main(int argc, char** argv){
    int n;
    cin >> n;
    PrintNum(n);

    system("PAUSE");
    return 0;
}