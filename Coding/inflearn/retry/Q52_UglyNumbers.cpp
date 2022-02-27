#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> ugly(n + 1);

    ugly[1] = 1;

    int *p2, *p3, *p5;
    p2 = &ugly[1];
    p3 = &ugly[1];
    p5 = &ugly[1];

    int val = 2147000000;
    for(int i = 2; i <= n; ++i)
    {
        if (*p2 * 2 < *p3 * 3)
            val = *p2 * 2;
        else
            val = *p3 * 3;

        if (*p5 * 5 < val)
            val = *p5 * 5;

        if (val == *p2 * 2)
            p2++;
        if (val == *p3 * 3)
            p3++;
        if (val == *p5 * 5)
            p5++;
        ugly[i] = val;
    }
    cout << ugly[n] << endl;
    return 0;
}