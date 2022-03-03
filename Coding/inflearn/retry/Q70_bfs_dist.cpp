#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	vector<int> *map;
	queue<int> q;
	int *check;
	int *dist;

	int n, m;
	cin >> n >> m;

	map = new vector<int>[n + 1];
	check = new int[n + 1]();
	dist = new int[n + 1]();

	int n1, n2;
	for (int i = 1; i <= m; ++i)
	{
		cin >> n1 >> n2;
		map[n1].push_back(n2);
	}

	int x;
	q.push(1);
	check[1] = 1;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); ++i)
		{
			if (check[map[x][i]] == 0)
			{
				check[map[x][i]] = 1;
				q.push(map[x][i]);
				dist[map[x][i]] = dist[x] + 1;
			}
		}
	}

	for (int i = 2; i <= n; ++i)
        cout << i << " : " << dist[i] << endl;
    system("PAUSE");
	return 0;
}