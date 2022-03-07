#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int check[30];
typedef struct s_map
{
    int v1, cost;
    
    s_map(int a, int c)
    {
        v1 = a;
        cost = c;
    }

    bool operator < (const s_map &x) const
    {
        return cost > x.cost;
    }
} t_map;

int main()
{
    int v, e;
    cin >> v >> e;
    
    priority_queue<t_map> pq;
    vector<pair<int, int>> map[30];
    int a, b, c;
    for (int i = 0; i < e; ++i)
    {   
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }

    int ans = 0;
    pq.push(t_map(1, 0)); //#1 vertex 선택
    while (!pq.empty())
    {
        t_map tmp = pq.top();
        pq.pop();
        int v = tmp.v1;
        int cost = tmp.cost;
        if (check[v] == 0)
        {
            ans += cost;
            check[v] = 1;
            for (int i = 0; i < map[v].size(); ++i)
            {
                pq.push(t_map(map[v][i].first, map[v][i].second));
            }
        }
    }
    cout << ans << endl;
    return 0;
}