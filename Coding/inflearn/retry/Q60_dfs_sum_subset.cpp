#include <iostream>

using namespace std;

string ans = "NO";

string dfs(int arr[], int sum, int x, int sub_sum, int n)
{
    if (sub_sum > sum / 2)
        return ans;
    if (x > n)
    {
        if (sub_sum == sum - sub_sum)
        { 
            ans = "YES";
            return ans;
        }
    }
    else
    {
        dfs(arr, sum, x + 1, sub_sum + arr[x], n);
        dfs(arr, sum, x + 1, sub_sum, n);
    }
    return ans;
}

int main()
{
    int n, sum = 0;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    dfs(arr, sum, 0, 0, n);
    cout << ans << endl;
    return 0;
}