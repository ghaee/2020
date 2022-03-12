#include <vector>
#include <string>
#include <iostream>
/*

4578	[1, 4, 99, 35, 50, 1000]	2308
1999	[2, 11, 20, 100, 200, 600]	2798

*/
using namespace std;

int answer = 99999999;
vector<int> coins = {1, 5, 10, 50, 100, 500};
vector<int> cnt(6, 0);
vector<int> check(6, 0);

void dfs(int origin, int money, vector<int> costs, int x)
{   
    int a = 0;
    int size = costs.size();
    if (x == -1)
    {
        int sum = 0;
        for (int i = 0; i < size; ++i)
        {
            a += coins[i] * cnt[i];
            sum += cnt[i] * costs[i];
        }

        if (a == origin)
            answer = min(answer, sum);
        return ;
    }
    else
    {
        check[x] = 1;
        cnt[x] = money / coins[x];
        int tmp = money % coins[x];
        dfs(origin, tmp, costs, x - 1);
        
        check[x] = 0;
        cnt[x] = 0;
        dfs(origin, money, costs, x - 1);
    }

}

int solution(int money, vector<int> costs)
{
    int size = costs.size();
    dfs(money, money, costs, size - 1);

    return answer;
}

int main()
{
    //vector<int> costs = {1, 4, 99, 35 , 50, 1000};
    //cout << solution(4578, costs) << endl;

    vector<int> costs = {2, 11, 20, 100, 200, 600};
    cout << solution(1999, costs) << endl;
    system("PAUSE");
    return 0;
}