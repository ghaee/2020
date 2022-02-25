#include <iostream>

using namespace std;

int H, W;
int h, w;                                                                     
int **tab;

void solve(int k, int l, int* max)
{
        if(k + h > H && w + l > W)
                return ;
        int sum = 0;
        for(int i = 0; i < h; ++i)
        {
                for(int j = 0; j < w; ++j)
                {
                        sum += tab[k + i][l + j];
                }
        }
        if(sum > *max)
                *max = sum;
        if (w + l + 1 <= W)
        {
                solve(k, l + 1, max);
        }
        else if (h + k + 1 <= H)
        {
                l = 0;
                solve(k + 1, l, max);
        }
}

int main()
{
        cin >> H >> W;

        tab = new int*[H];

        for(int i = 0; i < H; ++i)
        {
                tab[i] = new int[W];
        }

        for(int i = 0; i < H; ++i)
        {
                for(int j = 0; j < W; ++j)
                {
                        cin >> tab[i][j];
                }
        }

        cin >> h >> w;

        int max = -21476000;
        solve(0, 0, &max);
        cout << max << endl;
        return 0;
}
