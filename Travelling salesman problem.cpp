#include <iostream>
using namespace std;
int x[100], k, n, m, as, es, a[100][100], i, j;
void valid(int x[], int k, int& es)
{
	int i;
	es = 1;
	if (a[x[k]][x[k - 1]] == 0)
		es = 0;
	for (i = 1; i <= k - 1; i++)
		if (x[i] == x[k])
			es = 0;
	if (k == n && a[x[n]][x[1]] == 0)
		es = 0;
}
void succ(int x[], int k, int& as)
{
	if (x[k] < n)
	{
		x[k]++;
		as = 1;
	}
	else
		as = 0;
}
void afis(int x[], int k)
{
	int i;
	for (i = 1; i <= k; i++)
		cout << x[i] << " ";
	cout << endl;
}
int main()
{
	cout << "n="; cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	k = 1;
	x[k] = 1;
	k = 2;
	x[k] = 1;
	while (k > 1)
	{
		do
		{
			succ(x, k, as);
			if (as)
				valid(x, k, es);
		} while (as && !es);
		if (as)
		{
			if (k == n)
			{
				afis(x, k);
			}
			else
			{
				k++;
				x[k] = 1;
			}
		}
		else
			k--;
	}
}

