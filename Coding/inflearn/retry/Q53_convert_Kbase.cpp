#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<char> ans;

    while(n > 0)
    {
        if (n % k < 10)
        {
            ans.push_back(n % k + 48);
        }
        else
        {
            ans.push_back(n % k + 55);
        }
        n /= k;
    }

    for(auto i = ans.rbegin(); i != ans.rend(); ++i)
    {
        cout << *i;
    }
    return 0;
}