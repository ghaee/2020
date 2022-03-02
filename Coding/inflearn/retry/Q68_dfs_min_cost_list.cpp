#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int,int>> *map;
int *check;

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
        for (int i = 0; i < map[x].size(); ++i)
        {
            if (check[map[x][i].first] == 0)
            {
                check[map[x][i].first] = 1;
                dfs(map[x][i].first, sum + map[x][i].second, cost);
                check[map[x][i].first] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    map = new vector<pair<int,int>>[n + 1];
    check = new int[n + 1](); //initialze to 0
    
    int n1, n2, w;

    for (int i = 1; i <= m; ++i)
    {
        cin >> n1 >> n2 >> w;
        map[n1].push_back(make_pair(n2,w));
    }

    int cost = 2147000000;
    
    check[1] = 1;
    dfs(1, 0, &cost);

    cout << cost << endl;

    return 0;
}