#include <iostream>
#include <vector>

using namespace std;
void convert(vector<int> *v, int n)
{
    if (n == 0)
        return ;
    v->push_back(n % 2);
    convert(v, n / 2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    convert(&v, n);

    for(auto i = v.rbegin(); i != v.rend(); ++i)
        cout << *i;
    cout << endl;

    return 0;
}