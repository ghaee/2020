#include <iostream>
#include <vector>

using namespace std;

int n, m;

void dfs(vector<int> check, vector<vector<int>> map, int x, int *cnt)
{
    if (x == n)
    {
        (*cnt)++;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (map[x][i] == 1 && check[i] == 0)
            {
                check[i] = 1;
                dfs(check, map, i, cnt);
                check[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));

    int n1, n2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> n1 >> n2;
        map[n1][n2] = 1;
    }

    int cnt = 0;

    vector<int> check(n + 1, 0);

    check[1] = 1;
    dfs(check, map, 1, &cnt);

    cout << cnt << endl;
    return 0;
}