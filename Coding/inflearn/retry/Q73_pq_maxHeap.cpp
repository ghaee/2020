#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int a;
    priority_queue<int> pq;
    cin >> a;
    while (a != -1)
    {
        if (a == 0)
        {
            if (pq.empty())
                cout << "-1\n";
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
        {
            pq.push(a);
        }
        cin >> a;
    }
    return 0;
}