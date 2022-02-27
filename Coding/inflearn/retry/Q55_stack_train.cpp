#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n, train, order = 1;
    cin >> n;

    vector<char> ans;
    stack<int> s;

    for(int i = 0; i < n; ++i)
    {
        cin >> train;
        s.push(train);
        ans.push_back('P');
        while(!s.empty())
        {
            if(order == s.top())
            {
                s.pop();
                order++;
                ans.push_back('O');
            }
            else break;
        }
    }
    if(!s.empty()) cout << "impossible\n";
    else
    {
        for(auto i = ans.begin(); i != ans.end(); ++i)
            cout << *i;
    }
    return 0;
}