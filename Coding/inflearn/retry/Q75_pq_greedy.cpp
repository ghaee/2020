#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s_income
{
    int money, deadline;
    s_income(int m, int d)
    {
        money = m;
        deadline = d;
    }

    bool operator < (const s_income &s) const
    {
        return deadline > s.deadline;
    }
} t_income;

int main()
{
    int n, m, d, max = -2147000000;
    cin >> n;

    priority_queue<int> pq;
    vector<t_income> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> m >> d;
        v.push_back(s_income(m, d));
        if (d > max)
        {
            max = d; //최대 강연일수, 이 안에서 스케쥴링
        }      
    }

    sort(v.begin(), v.end());

    // cout << "========= sorted ==========" << endl;
    // for (auto i : v)
    // {
    //     cout << i.money << " " << i.deadline << endl;
    // }

    int j = 0;
    int sum = 0;
    for (int i = max; i > 0; --i) //i 일 째 어떤 강연을 할지 마지막날부터 계산
    {
        for (; j < n; ++j)
        {
            if (v[j].deadline < i) //deadline 짧으면 강연 못함
            {
                break;
            }
            pq.push(v[j].money); //i일째의 가능한 강연 수입 내림차순 정렬
        }
        if(!pq.empty()){
            sum += pq.top(); //가능한 강연들 중 제일 큰 값만 취한다.
            pq.pop();
        }
    }
    cout << sum << endl;

    return 0;
}