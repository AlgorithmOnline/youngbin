#include<iostream>
#include<queue>
#include<utility>
#define INF 999999999
#define max_n 50
using namespace std;

int N, M;
int ans;
int s_x, s_y;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[max_n + 1][max_n + 1]; // ºñ¹ö -4, µ¹ -1, °í½¿ -5, 0~100 : ºø¹°
bool visit[max_n + 1][max_n + 1];

void init();
void bfs();
void visit_clear();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	ans = INF;
	bfs();
	if (ans == INF) cout << "KAKTUS\n";
	else cout << ans << '\n';

	return 0;
}
void visit_clear()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			visit[i][j] = false;
		}
	}
}
void bfs()
{
	queue<pair<int, int>> q;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				map[i][j] = 0;
				visit[i][j] = true;
			}
		}
	}

	while (1)
	{
		if (q.empty()) break;

		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = cur_x + dx[k];
			int ny = cur_y + dy[k];

			if (nx < 1 || ny < 1 || nx >N || ny > M) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == -4 || map[nx][ny] == -1) continue;

			visit[nx][ny] = true;
			map[nx][ny] = map[cur_x][cur_y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	visit_clear();
	q.push(make_pair(s_x, s_y));
	visit[s_x][s_y] = true;
	int depth = 1;

	while (1)
	{
		if (q.empty()) break;

		int q_size = q.size();

		for (int i = 0; i < q_size; ++i)
		{
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int nx = cur_x + dx[k];
				int ny = cur_y + dy[k];

				if (nx < 1 || ny < 1 || nx >N || ny > M) continue;
				if (visit[nx][ny]) continue;
				if (map[nx][ny] == -1) continue;
				if (map[nx][ny] == -4)
				{
					if (ans > depth) ans = depth;
					continue;
				}
				if (map[nx][ny] != 0 && map[nx][ny] <= depth) continue;

				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
		++depth;
	}

}
void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			char ch;
			cin >> ch;
			switch (ch)
			{
			case 'D': map[i][j] = -4; break;
			case '*': map[i][j] = 1; break;
			case '.': map[i][j] = 0; break;
			case 'S': map[i][j] = 0; s_x = i; s_y = j; break;
			case 'X': map[i][j] = -1; break;
			}
		}
	}
}