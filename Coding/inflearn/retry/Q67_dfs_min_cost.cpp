#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[21][21];
int check[21];
void dfs(int x, int sum, int *cost)
{
    if (x == n)
    {
        if (sum < *cost)
        {
            *cost = sum;
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (map[x][i] > 0 && check[i] == 0)
            {
                check[i] = 1;
                dfs(i, sum + map[x][i], cost);
                check[i] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    
    int n1, n2, w;
    for (int i = 1; i <= m; ++i)
    {
        cin >> n1 >> n2 >> w;
        map[n1][n2] = w;   
    }

    int cost = 2147000000;
    check[1] = 1;
    dfs(1, 0, &cost);
    cout << cost << endl;
    return 0;
}