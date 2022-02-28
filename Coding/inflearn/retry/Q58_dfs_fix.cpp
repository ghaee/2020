#include <iostream>

using namespace std;

void dfs(int n)
{
	if (n > 7) return ;
	else
	{
		//pre : cout << n << " ";
		dfs(n * 2);
		//in : cout << n << " ";
		dfs(n * 2 + 1);
		//post : cout << n << " ";
	}
}

int main()
{
	dfs(1);
	cout << endl;
	return 0;
}