#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define max_n 8
using namespace std;

int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int dupli_map[max_n + 1][max_n + 1];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[max_n*max_n + 1];
int c;
int w_size;
int v_size;
int ans;
vector<pair<int, int>> virus;
vector<pair<int, int>> w;

void init();
void comb(int cur, int depth);
void duplicate();
void visit_clear();
void bfs();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	comb(0, 0);
	
	cout << ans << '\n';
	return 0;
}
void comb(int cur, int depth)
{
	if (depth == 3)
	{
		duplicate();
		
		for (int i = 0; i < w_size; ++i)
		{
			if (check[i])
			{
				int cur_x = w[i].first;
				int cur_y = w[i].second;
				dupli_map[cur_x][cur_y] = 1;
			}
		}
		visit_clear();
		
		bfs();

		return;
	}
	
	for (int i = cur; i < w_size; ++i)
	{
		if (check[i] == false)
		{
			check[i] = true;
			comb(i, depth + 1);
			check[i] = false;
		}
	}
}
void bfs()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < v_size; ++i)
	{
		int cur_x = virus[i].first;
		int cur_y = virus[i].second;

		visit[cur_x][cur_y] = true;
		q.push({ cur_x, cur_y });
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

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (visit[nx][ny]) continue;
			if (dupli_map[nx][ny] != 0) continue;

			dupli_map[nx][ny] = 2;
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (dupli_map[i][j] == 0) ++res;
		}
	}

	ans = max(ans, res);
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
void duplicate()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dupli_map[i][j] = map[i][j];
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
			if (map[i][j] == 2) virus.push_back({i,j});
			if (map[i][j] == 0) w.push_back({ i,j });
		}
	}
	v_size = virus.size();
	w_size = w.size();
}