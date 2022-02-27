#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    char c[31];
    stack<char> s;

    cin >> c;
    int i = 0;
    while(c[i])
    {
        if (c[i] == '(')
            s.push(c[i]);
        else
        {
            if(s.empty())
            {
                cout << "NO\n";
                return 0;
            }
            else
                s.pop();
        }
        ++i;
    }
    if(s.empty())
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
    return 0;
}