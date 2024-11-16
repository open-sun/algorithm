#include<iostream>
#include<vector>
#include<deque>
using namespace std;
bool valid = true;
bool dfs(vector<vector<int>>& tu, int node, vector<int>& visited, vector<int>& path,vector<int>&circle) {
	visited[node] = 1;
	path.push_back(node);
	circle.push_back(node);
	for (int i = 1; i < tu[node].size(); ++i) {
		int next_node = tu[node][i];
		if (next_node != 0) {
			if (visited[next_node] == 0) {
				if (dfs(tu, next_node, visited, path,circle)) {
					return true;
				}
			}
			else if (visited[next_node] == 1) {

				int start_index = 0;
				cout << "NO" << endl;
				for (int j = start_index; j < path.size(); ++j) {
					cout << path[j] << ",";
				}
				cout << path[start_index];
				cout << endl;

				return true;
			}
		}
	}
	visited[node] = 3;
	path.pop_back();
	return false;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>inner;
	vector<vector<int>>tu;
	for (int i = 0; i <= n; i++)
	{
		int temp = 0;
		inner.push_back(temp);
	}
	for (int i = 0; i <= n; i++)
	{
		tu.push_back(inner);
	}
	for (int i = 0; i < m; i++)
	{
		int temp1 = 0, temp2 = 0;
		cin >> temp1 >> temp2;
		tu[temp1][temp2] = temp2;
	}
	vector<int>symbol;
	for (int i = 0; i <= n; i++)
	{
		symbol.push_back(0);
	}
	deque<int>beginner;
	vector<int>du;
	for (int i = 0; i <= n; i++)
	{
		du.push_back(0);
	}
	for (int i = 1; i <= n; i++)
	{
		int number = 0;
		for (int j = 1; j <= n; j++)
		{
			if (tu[j][i] != 0)
			{
				number++;
			}
		}
		du[i] = number;
	}
	for (int i = 1; i <= n; i++)
	{
		int flag = 1;
		for (int j = 1; j <= n; j++)
		{
			if (tu[j][i] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			beginner.push_back(i);
			symbol[i] = 1;
		}
	}

	vector<int>result;
	while (!beginner.empty())
	{
		result.push_back(beginner.front());
		int temp5 = beginner.front();
		beginner.pop_front();
		symbol[temp5] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (tu[temp5][i] != 0)
			{
				tu[temp5][i] = 0;
				du[i]--;

				if (du[i] == 0 && symbol[i] == 0)
				{
					beginner.push_back(i);
					symbol[i] = 1;
				}
			}
		}
	}

	if (result.size() == n)
	{
		cout << "YES" << endl;
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << ",";
		}

	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < result.size(); j++)
			{
				if (i == result[j])
				{
					symbol[i] = 9;
				}
			}
		}
		vector<int>path;
		vector<int>circle;
		for (int i = 1; i <= n; i++)
		{
			if (symbol[i] == 0 && valid)
			{
				if (dfs(tu, i, symbol,path,circle)) {

					return 0;
				}

			}
		}
	}
	return 0;
}