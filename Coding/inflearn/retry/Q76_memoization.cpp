#include <iostream>
#include <vector>

using namespace std;

int d[21][21];

int dfs(int n, int r)
{
    if (d[n][r] > 0) return d[n][r]; //memoization
    if (n == r || r == 0)
        return 1;
    return d[n][r] = dfs(n - 1, r - 1) + dfs(n - 1, r);
}

int main()
{
    int n, r;
    cout << dfs(n, r) << endl;
    system("PAUSE");
    return 0;
}