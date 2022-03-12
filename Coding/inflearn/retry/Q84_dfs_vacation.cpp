#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = -2147000000;
vector<int> t, p;


void dfs(int k, int sum)
{
    if (k > n)
    {
        answer = max(answer, sum);
    }
    else
    {
        if (k + t[k] <= n + 1)
        {
            dfs(k + t[k], sum + p[k]);
        }
        dfs(k + 1, sum);
    }
}

int main()
{
    cin >> n;

    int a, b;
    
    t.push_back(0);
    p.push_back(0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        t.push_back(a);
        p.push_back(b);
    }

    dfs(1, 0);
    cout << answer << endl;
    return 0;
} 