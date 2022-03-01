#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));

	int n1, n2, w;

	for (int i = 1; i <= m; ++i)
	{
		cin >> n1 >> n2 >> w;
		map[n1][n2] = w;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << map[i][j] << " ";
		cout << endl;
	}
	return 0;
}