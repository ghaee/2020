#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> v;

void dfs(int n){
   if(n>7) return;
   else{
       //prefix v.push_back(n);
       dfs(n*2);
       // infix v.push_back(n);
       dfs(n*2 + 1);
       //postfix
       v.push_back(n);
    }
}

int main(int argc, char** argv){
    
    dfs(1);
    for(auto i = v.begin(); i != v.end(); ++i){
        cout << *i <<" ";
    }
    system("PAUSE");
    return 0;
}