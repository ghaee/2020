#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n1, n2;

	queue<int> q;
	vector<int> map[7];
	int check[8] = {0,};

	for (int i = 1; i <= 7; ++i)
	{
		cin >> n1 >> n2;
		map[n1].push_back(n2);
	}

	int x;
	q.push(1)

	while (!q.empty())
	{
		x = q.front();
		cout << x << " ";
		q.pop();
		for (int i = 0; i < map[x].size(); ++i)
		{
			if (check[map[x][i]] == 0)
			{
				check[map[x][i]] = 1;
				q.push(map[x][i]);
				check[map[x][i]] = 0;
			}
		}
	}
	cout << endl;
	return 0;
}