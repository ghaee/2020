#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    queue<int> q;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    int a = 0;
    while (!q.empty())
    {
        // for (int i = 1; i < k; ++i)
        // {
        //     q.push(q.front());
        //     q.pop();
        // }
        // q.pop();
        // if (q.size() == 1)
        // {
        //     cout << q.front() << endl;
        //     break;
        // }
        if (a + 1 < k)
        {
            q.push(q.front());
            q.pop();
            ++a;
        }
        if (a + 1 == k)
        {
            q.pop();
            a = 0;
        }
        if (q.size() == 1)
        {
            cout << q.front() <<endl;
            break;
        }
    }
    return 0;
}