#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
// Stack
int main(int argc, char** argv){
    int n, tmp, j = 1;
    cin >> n;
    
    stack<int> s;
    vector<char> answer;
    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        s.push(tmp);
        answer.push_back('P');
        while(true){
            if(s.empty()) break;
            if(j == s.top()){
                s.pop();
                j++;
                answer.push_back('O');
            }
            else break;
        }
    }
    if(!s.empty()) cout << "impossible\n";
    else{
        for(auto i = answer.begin(); i != answer.end(); ++i){
            cout << *i;
        }
    }
    //system("PAUSE");
    return 0;
}