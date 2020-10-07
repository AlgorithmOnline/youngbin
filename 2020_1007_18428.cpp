#include<iostream>
#include<vector>
#include<utility>
#define max_n 6
using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> t;
bool check[max_n * max_n + 1];
int map[max_n + 1][max_n + 1];
int dupli_map[max_n + 1][max_n + 1];
int n;
int v_size;
int t_size;
bool ans;
int temp;
void init();
void dupli();
void print();
void solution(int cur, int depth);
void check_func();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	ans = false;
	solution(0, 0);

	if (ans) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
void solution(int cur, int depth)
{
	if (ans) return;
	
	if (depth == 3)
	{
		dupli();
		for (int i = 0; i < v_size; ++i)
		{
			if (check[i])
			{
				dupli_map[v[i].first][v[i].second] = 4;
			}
		}

		check_func();

		return;
	}

	for(int i = cur; i < v_size; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			solution(i, depth + 1);
			check[i] = false;
		}
	}
}
void check_func()
{
	if (dupli_map[1][4] == 4 && dupli_map[2][2] == 4 && dupli_map[3][3] == 4) print();

	bool t_check = false;

	for (int i = 0; i < t_size; ++i)
	{
		if (t_check == true) break;
		int x = t[i].first;
		int y = t[i].second;
		
		for (int i = x-1; i >= 1; --i)
		{
			if (dupli_map[i][y] == 4) break;
			if (dupli_map[i][y] == 2)
			{
				t_check = true;
				break;
			}
		}
		for (int i = x+1; i <= n; ++i)
		{
			if (dupli_map[i][y] == 4) break;
			if (dupli_map[i][y] == 2)
			{
				t_check = true;
				break;
			}
		}
		for (int i = y-1; i >=1; --i)
		{
			if (dupli_map[x][i] == 4) break;
			if (dupli_map[x][i] == 2)
			{
				t_check = true;
				break;
			}
		}
		for (int i = y+1; i <= n; ++i)
		{
			if (dupli_map[x][i] == 4) break;
			if (dupli_map[x][i] == 2)
			{
				t_check = true;
				break;
			}
		}
	}
	if (t_check == false) ans = true;
}
void print()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << dupli_map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void dupli()
{
	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dupli_map[i][j] = map[i][j];
		}
	}
}
void init()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			char ch;
			cin >> ch;
			if (ch == 'X')
			{
				map[i][j] = 0;
				v.push_back({ i,j });
			}
			else if (ch == 'T')
			{
				map[i][j] = 1;
				t.push_back({ i,j });
			}
			else if (ch == 'S') map[i][j] = 2;
		}
	}
	v_size = v.size();
	t_size = t.size();
}