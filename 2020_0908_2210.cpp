#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define max_n 5
using namespace std;

vector<string> v;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[max_n + 1][max_n + 1];
void input();
void solution(int cur_x, int cur_y, int depth, string str);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 1; i <= max_n; ++i)
	{
		for (int j = 1; j <= max_n; ++j)
		{
			string str = "";
			str += char(map[i][j] + '0');
			solution(i, j, 1, str);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int v_size = v.size();

	cout << v_size << '\n';
	return 0;
}
void solution(int cur_x, int cur_y, int depth, string str)
{
	if (depth >= 6)
	{
		v.push_back(str);
		return;
	}

	for (int k = 0; k < 4; ++k)
	{
		int nx = cur_x + dx[k];
		int ny = cur_y + dy[k];
		if (nx < 1 || ny < 1 || nx > max_n || ny > max_n) continue;

		solution(nx, ny, depth + 1, str + char(map[nx][ny] + '0'));
	}
}
void input()
{
	for (int i = 1; i <= max_n; ++i)
	{
		for (int j = 1; j <= max_n; ++j)
		{
			cin >> map[i][j];
		}
	}
}