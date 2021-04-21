#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
//STL stack 사용
int main(int argc, char ** argv){
    stack<char> s;
    char a[31];
    cin >> a;
    for(int i = 0; a[i]!= '\0'; ++i){
        if(a[i]=='(') s.push(a[i]);
        else{
            if(s.empty()){ cout << "NO\n" << endl; return 0;}
            else s.pop();
        }
    }
    if(s.empty()) cout << "YES\n" <<endl;
    else cout << "NO\n" << endl;
    //system("PAUSE");
    return 0;
}