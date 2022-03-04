#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int d[3] = {1, -1, 5};
    int check[10001] = {0,};
    queue<int> q;
    int s, e;
    cin >> s >> e;

    q.push(s);
    check[s] = 1;

    int x;
    int pos;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < 3; ++i)
        {
            pos = x + d[i];
            if (pos < 1 || pos > 10000)
                continue;
            if (pos == e)
            {
                cout << check[x] << endl;
                return 0;
            }
            if (check[pos] == 0)
            {
                check[pos] = check[x] + 1;
                q.push(pos);
            }
        }
    }
    return 0;
}