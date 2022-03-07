#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 2147000000

typedef struct s_map
{
    int v, cost;
    s_map(int a, int c)
    {
        v = a;
        cost = c;
    }

    bool operator < (const s_map &x) const
    {
        return cost > x.cost;
    }

} t_map;

int main()
{
    int n ,m;
    cin >> n >> m;

    priority_queue<t_map> pq;
    vector<pair<int, int>> *map;
    vector<int> dist(n + 1, INF);
    map = new vector<pair<int, int>>[n + 1];
    
    int a, b, c;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }

    pq.push(s_map(1, 0));
    dist[1] = 0;
    while (!pq.empty())
    {
        t_map tmp = pq.top();
        pq.pop();
        int v = tmp.v;
        int cost = tmp.cost;

        if (cost > dist[v]) continue;
        for (int i = 0; i < map[v].size(); ++i)
        {
            int next = map[v][i].first;
            int next_c = cost + map[v][i].second;
            if (dist[next] > next_c)
            {
                dist[next] = next_c;
                pq.push(s_map(next, next_c));
            }
        }
    }
    cout << "===================================" << endl;
    for(int i = 2; i <= n; ++i){
        if (dist[i] != INF)
            cout << i << " : " << dist[i] << endl;
        else
            cout << i << " : impossible" << endl;
    }
    cout << "===================================" << endl;
    system("PAUSE");
    return 0;
}