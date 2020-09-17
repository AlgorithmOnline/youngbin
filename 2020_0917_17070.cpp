#include<iostream>
#define max_n 16
using namespace std;

int map[max_n + 1][max_n + 1];
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };
int n;
bool visit[max_n + 1][max_n + 1];
int ans;
void init();
void dfs(int cur_x, int cur_y, int cur_move);
bool check_area(int x, int y);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();

	dfs(1, 2, 1);
	
	cout << ans << '\n';

	return 0;
}
void dfs(int cur_x, int cur_y, int cur_move)// cur_move -> 1:가로, 2: 세로, 3:대각
{
	if (cur_x == n && cur_y == n)
	{
		++ans;
		return;
	}

	if (cur_move == 1)
	{
		int nx = cur_x + dx[0];
		int ny = cur_y + dy[0];
		if (check_area(nx, ny)) // 가 -> 가
		{
			visit[nx][ny] = true;
			dfs(nx, ny, 1);
			visit[nx][ny] = false;
			
			int nx1, ny1, nx2, ny2;
			nx1 = cur_x + dx[1];
			ny1 = cur_y + dy[1];
			nx2 = cur_x + dx[2];
			ny2 = cur_y + dy[2];
			if (check_area(nx1, ny1) && check_area(nx2, ny2)) // 가 -> 대
			{
				visit[nx][ny] = true;
				visit[nx1][ny1] = true;
				visit[nx2][ny2] = true;

				dfs(nx2, ny2, 3);

				visit[nx][ny] = false;
				visit[nx1][ny1] = false;
				visit[nx2][ny2] = false;
			}
		}
	}
	else if (cur_move == 2)
	{
		int nx = cur_x + dx[1];
		int ny = cur_y + dy[1];
		if (check_area(nx, ny)) // 세 -> 세
		{
			visit[nx][ny] = true;
			dfs(nx, ny, 2);
			visit[nx][ny] = false;

			int nx1, ny1, nx2, ny2;
			nx1 = cur_x + dx[0];
			ny1 = cur_y + dy[0];
			nx2 = cur_x + dx[2];
			ny2 = cur_y + dy[2];
			if (check_area(nx1, ny1) && check_area(nx2, ny2)) // 세 -> 대
			{
				visit[nx][ny] = true;
				visit[nx1][ny1] = true;
				visit[nx2][ny2] = true;

				dfs(nx2, ny2, 3);

				visit[nx][ny] = false;
				visit[nx1][ny1] = false;
				visit[nx2][ny2] = false;
			}
		}
	}
	else if (cur_move == 3)
	{
		int nx = cur_x + dx[0];
		int ny = cur_y + dy[0];
		if (check_area(nx, ny)) // 대 -> 가
		{
			visit[nx][ny] = true;
			dfs(nx, ny, 1);
			visit[nx][ny] = false;
		}
		int nx1 = cur_x + dx[1];
		int ny1 = cur_y + dy[1];
		if (check_area(nx1, ny1)) // 대 -> 세
		{
			visit[nx1][ny1] = true;
			dfs(nx1, ny1, 2);
			visit[nx1][ny1] = false;
		}

		if (check_area(nx, ny) && check_area(nx1, ny1)) // 대 -> 대
		{
			int nx2 = cur_x + dx[2];
			int ny2 = cur_y + dy[2];

			if (check_area(nx2, ny2))
			{
				visit[nx][ny] = true;
				visit[nx1][ny1] = true;
				visit[nx2][ny2] = true;

				dfs(nx2, ny2, 3);

				visit[nx][ny] = false;
				visit[nx1][ny1] = false;
				visit[nx2][ny2] = false;
			}
		}
	}
}
bool check_area(int x, int y)
{
	bool res = true;

	if (x < 1 || y < 1 || x > n || y > n) res = false;
	if (map[x][y] != 0 || visit[x][y]) res = false;

	return res;
}
void init()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}
}