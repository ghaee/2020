#include <iostream>
#include <vector>

using namespace std;

void dfs(int v[], int x, int n)
{
	if (x > n)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (v[i] == 1)
				cout << i << " ";
		}
		cout << endl;
	}
	else
	{
		v[x] = 1;
		dfs(v, x + 1, n);
		v[x] = 0;
		dfs(v, x + 1, n);
	}
}

int main()
{
	int n;
	cin >> n;

	int *v = new int[n + 1];

	for (int i = 1; i <= n; ++i)
	{
		v[i] = 0;
	}

	dfs(v, 1, n);
	return 0;
}