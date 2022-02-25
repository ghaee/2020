#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tab(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; ++i)
    {
        cin >> tab[0][i];
    }
    
    for(int i = 1; i <= n; ++i)
    {
        cin >> tab[i][0];
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            tab[i][j] = tab[0][j];
            if(tab[i][j] > tab[i][0])
            {
                tab[i][j] = tab[i][0];
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <=n; ++j)
        {
            sum += tab[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}