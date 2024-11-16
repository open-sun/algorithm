#include<iostream>
using namespace std;
int a[100][100] = { 0 };
int p[100] = { 0 };
int w[100] = { 0 };
bool peidui(int l)
{
	int flag = 0;
		for (int j = 1; j < 100; j++)
		{
			if (a[l][j] != 0 && p[j] == 0)
			{
				p[j] = l;
				w[l] = j;
				flag = 1;
				return true;
			}
			else if (a[l][j] != 0&&peidui(p[j]))
			{
				p[j]=l;
				w[l] = j;
				flag = 1;
				return true;
			}
		}
		if (flag == 0)
		return false;
}
int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	int u = 0, v = 0;
	while (true)
	{
		cin >> u >> v;
		a[u][v] = 1;
		if ((u == -1)&& (v == -1))
		break;
	}
	for(int i=1;i<=m;i++)
	{
		peidui(i);
	}
	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		if (w[i] != 0)
			sum++;
	}
	cout << sum<<endl;
	for (int i = 0; i < 100; i++)
	{
		if (w[i] != 0)
		{
			cout << i << " " << w[i] << endl;
		}
	}
	return 0;
}