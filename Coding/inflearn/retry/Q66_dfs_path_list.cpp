#include <iostream>
#include <vector>

using namespace std;

vector<int> *map;
int *check;
int n, m;

void dfs(int x, int *cnt)
{
    if (x == n)
    {
        (*cnt)++;
    }
    else
    {
        for (int i = 0; i < map[x].size(); ++i)
        {
            if (check[map[x][i]] == 0)
            {
                check[map[x][i]] = 1;
                dfs(map[x][i], cnt);
                check[map[x][i]] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    map = new vector<int> [n + 1];
    check = new int[n + 1];

    int n1, n2;
    for (int i = 1; i <= m; ++i)
    {
        cin >> n1 >> n2;
        map[n1].push_back(n2);
    }

    int  cnt = 0;
    check[1] = 1;
    dfs(1, &cnt);

    cout << cnt << endl;
    return 0;
}