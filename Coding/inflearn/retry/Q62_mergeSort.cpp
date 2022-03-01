#include <iostream>

using namespace std;

int *sort;

void mergeSort(int input[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(input, start, mid);
		mergeSort(input, mid + 1, end);

		int i, j;
		i = start;
		j = mid + 1;

		int k = start;

		while (i <= mid && j <= end)
		{
			if (input[i] > input[j])
				sort[k++] = input[j++];
			else
				sort[k++] = input[i++];
		}
		while (i <= mid)
			sort[k++] = input[i++];
		while (j <= end)
			sort[k++] = input[j++];

		for (int i = start; i <= end; ++i)
			input[i] = sort[i];
	}
}

int main()
{
	int n;
	cin >> n;

	sort = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> input[i];

	mergeSort(input, 0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << input[i] << " ";
	cout << endl;

	return 0;
}