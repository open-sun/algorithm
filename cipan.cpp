#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0, l = 0;
	cin >> n >> l;
	vector<int>list;
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		list.push_back(m);
	}
	sort(list.begin(), list.end());
	int sum = 0;
	int flag = 0;
	for (int i = 0; i < list.size(); i++)
	{
		sum += list[i];
		if (sum <= l)
		{
			flag++;
		}
		else
		{
			break;
		}
	}
	cout << flag;
	return 0;
}