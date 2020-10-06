#include<iostream>
#include<vector>
#include<utility>
#define max_n 9
using namespace std;

int map[max_n + 1][max_n + 1];
int N;
vector<pair<int, int>> v;
int cnt;
void input();
void print();
void dfs(int depth);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	dfs(0);
	return 0;
}
bool check(int x, int y, int num)
{
	bool res = true;

	for (int i = 1; i <= 9; ++i)
	{
		if (map[i][y] == num) return false;
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (map[x][i] == num) return false;
	}

	int t_x;
	int t_y;
	if (x >= 1 && x <= 3) t_x = 1;
	else if (x >= 4 && x <= 6) t_x = 4;
	else t_x = 7;

	if (y >= 1 && y <= 3) t_y = 1;
	else if (y >= 4 && y <= 6) t_y = 4;
	else t_y = 7;

	int e_x = t_x + 2;
	int e_y = t_y + 2;
	for (int i = t_x; i <= e_x; ++i)
	{
		for (int j = t_y; j <= e_y; ++j)
		{
			if (map[i][j] == num) return false;
		}
	}
	return res;
}
void dfs(int depth)
{
	if (cnt == depth)
	{
		print();
		exit(0);
	}
	for (int i = 1; i <= 9; ++i)
	{
		int x = v[depth].first;
		int y = v[depth].second;

		if (check(x, y, i))
		{
			map[x][y] = i;
			dfs(depth + 1);
			map[x][y] = 0;
		}
	}
}
void print()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void input()
{
	N = 9;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) v.push_back(make_pair(i, j));
		}
	}
	cnt = v.size();
}