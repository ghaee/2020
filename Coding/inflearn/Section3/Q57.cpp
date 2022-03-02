#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<char> s;

void convert(int n){
    if (n>0){
        s.push(n%2 + 48);
        convert(n/2);
    }
}

int main(int argc, char** argv){
    int n;
    cin >> n;
    convert(n);
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    //system("PAUSE");
    return 0;
}