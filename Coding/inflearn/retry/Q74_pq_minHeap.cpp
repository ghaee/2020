#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int a;
    priority_queue<int> pq_min;
    
    cin >> a;
    while (a != -1)
    {
        if (a == 0)
        {
            if (pq_min.empty())
                cout << "-1\n";
            else
            {
                cout << -pq_min.top() << endl;
                pq_min.pop();
            }
        }
        else
        {
            pq_min.push(-a);
        }
        cin >> a;
    }
    return 0;
}