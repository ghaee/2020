#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct s_loc
{
    int x, y, z;
    s_loc(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    
    bool operator < (const s_loc &o) const // <- 상수멤버함수
    {
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        if (z != o.z) return z < o.z;
        return x < o.x;
        //호출한 객체는 앞에(작게), 매개변수로 넘어온 객체는 뒤에(크게) -> 오름차순
    }

} t_loc;

int main()
{
    vector<t_loc> xy;
    xy.push_back(s_loc(2, 3, 5));
    xy.push_back(s_loc(3, 6, 7));
    xy.push_back(s_loc(2, 3, 1));
    xy.push_back(s_loc(5, 2, 3));
    xy.push_back(s_loc(3, 1, 6));

    cout << "========== origin ===========\n";
    for (auto i : xy)
    {
        cout << i.x << " " << i.y << " " << i.z << endl;
    }

    cout << "========== sorted ===========\n";
    sort(xy.begin(), xy.end());
    for (auto i : xy)
    {
        cout << i.x << " " << i.y << " " << i.z << endl;
    }
    system("PAUSE");
    return 0;
}