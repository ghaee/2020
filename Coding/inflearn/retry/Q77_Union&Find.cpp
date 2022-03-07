#include <iostream>
#include <vector>

using namespace std;

int UnF[10001];

int Find(int x)
{
    if (x == UnF[x]) return x;
    return UnF[x] = Find(UnF[x]); //memoization
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b) 
        UnF[a] = b; // b is friend of a
}


int main()
{
    int n, m;
    int f1, f2;
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        UnF[i] = i;

    for (int i = 1; i <= m; ++i)
    {
        cin >> f1 >> f2;
        Union(f1, f2);
    }
    cin >> f1 >> f2;
    f1 = Find(f1);
    f2 = Find(f2);

    if (f1 == f2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}