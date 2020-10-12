#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define max_n 50
using namespace std;

int ans;
int dx[8] = { -1,1,0,0,1,-1, 1,-1 };
int dy[8] = { 0,0,-1,1,1,-1,-1,1 };
int n, m;
bool visit[max_n + 1][max_n + 1];
int map[max_n + 1][max_n + 1];
void init();
void solution(int x, int y);
void visit_clear();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] == 0)
			{
				visit_clear();
				solution(i, j);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
void solution(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	int cnt = 0;
	bool tog = false;

	while (1)
	{
		if (q.empty()) break;

		int q_size = q.size();

		for (int i = 0; i < q_size; ++i) 
		{
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int k = 0; k < 8; ++k)
			{
				int nx = cur_x + dx[k];
				int ny = cur_y + dy[k];

				if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if (visit[nx][ny]) continue;

				visit[nx][ny] = true;
				if (map[nx][ny] == 1) tog = true;
				q.push({ nx,ny });
			}
		}
		++cnt;
		if (tog) break;
	}
	
	while (1) { if (q.empty()) break; q.pop(); }

	ans = max(cnt, ans);
}
void visit_clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visit[i][j] = false;
		}
	}
}
void init()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}
}