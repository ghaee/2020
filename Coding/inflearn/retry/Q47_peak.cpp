#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> tab(n + 2, vector<int>(n + 2, 0));

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            cin >> tab[i][j];
    }

    int cnt = 0;
    bool peak;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            peak = true;
            for(int k = 0; k < 4; ++k)
            {
                if(tab[i][j] <= tab[i + dx[k]][j + dy[k]])
                {
                    peak = false;
                    break;
                }
            }
            if(peak) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}