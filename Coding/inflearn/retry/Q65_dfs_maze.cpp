#include <iostream>

using namespace std;

int check[8][8];
int map[8][8];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int *cnt)
{
    if (x == 7 && y == 7)
    {
        (*cnt)++;
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            if (x + dx[i] > 7 || y + dy[i] > 7) continue;
            if (x + dx[i] < 1 || y + dy[i] < 1) continue;
            if (map[x + dx[i]][y + dy[i]] == 0 && check[x + dx[i]][y + dy[i]] == 0)
            {
                check[x + dx[i]][y + dy[i]] = 1;
                dfs(x + dx[i], y + dy[i], cnt);
                check[x + dx[i]][y + dy[i]] = 0;
            }
        }
    }
}

int main()
{
    for (int i = 1; i <= 7; ++i)
    {
        for (int j = 1; j <= 7; ++j)
        {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    check[1][1] = 1;
    dfs(1, 1, &cnt);
    cout << cnt << endl;

    return 0;
}