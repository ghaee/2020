#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int *mst;

typedef struct s_map
{
    int v1, v2, cost;
    
    s_map(int a, int b, int c)
    {
        v1 = a;
        v2 = b;
        cost = c;
    }

    bool operator < (s_map &x)
    {
        return cost < x.cost;
    }

} t_map;

int Find(int x)
{
    if (x == mst[x]) return x;
    return mst[x] = Find(mst[x]); //memoization
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b) 
        mst[a] = b;
}

int main()
{
    int v, e;
    cin >> v >> e;

    int a, b, c;
    vector<t_map> T;
    mst = new int[v + 1];
    
    for (int i = 1; i <= v; ++i)
        mst[i] = i;

    for (int i = 0; i < e; ++i)
    {
        cin >> a >> b >> c;
        T.push_back(s_map(a, b, c));
    }

    sort(T.begin(), T.end());

    int ans = 0;
    for (int i = 0; i < e; ++i)
    {
        int fa = Find(T[i].v1);
        int fb = Find(T[i].v2);
        if (fa != fb)
        {
            ans += T[i].cost;
            Union(fa, fb);
        }
    }
    cout << ans << endl;
    return 0;
}