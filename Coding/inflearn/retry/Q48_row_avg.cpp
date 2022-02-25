#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tab[9][9];
    int avg;
    int sum;
    int diff;
    int min;
    int val;

    for(int i = 0; i < 9; ++i)
    {
        sum = 0;
        for(int j = 0; j < 9; ++j)
        {
            cin >> tab[i][j];
            sum += tab[i][j];
        }
        avg = (sum / 9.0) + 0.5;
        cout << avg << " ";
        min = 2147000000;
        for(int j = 0; j < 9; ++j)
        {
            diff = abs(tab[i][j] - avg);  
            if(diff < min)
            {
                min = diff;
                val = tab[i][j];
            }
            else if (diff == min)
            {    if(tab[i][j] > val)
                    val = tab[i][j];
            }
        }
        cout << val << endl;
    }
    return 0;
}