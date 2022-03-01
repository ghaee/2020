#include <iostream>

using namespace std;

int n, m;
int cnt = 0;
int *arr;

void dfs(int x, int val)
{
    if (x == n)
    {
        if (val == m)
            cnt++;
    }
    else
    {
        dfs(x + 1, val + arr[x]);
        dfs(x + 1, val - arr[x]);
        dfs(x + 1, val);
    }
}

int main()
{
    cin >> n >> m;

    arr = new int[n + 1];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    
    dfs(0, 0);

    if (cnt == 0)
        cout << "-1\n";
    else
        cout << cnt << endl;
    return 0;
}