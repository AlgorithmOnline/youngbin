#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#define INF 9999999
#define max_n 100
using namespace std;
typedef struct 
{
	int x;
	int y;
	int move;
	int cnt;
}A;
int n, m;
int start_x, start_y, end_x, end_y;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char map[max_n + 1][max_n + 1];
int visit[max_n + 1][max_n + 1];
void init();
void bfs();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	bfs();
	
	cout << visit[end_x][end_y] << '\n';
	return 0;
}
void bfs()
{
	queue<A> q;

	for (int i = 0; i < 4; ++i)
	{
		q.push({ start_x, start_y, i, 0 });
	}
	visit[start_x][start_y] = 0;

	while (1)
	{
		if (q.empty()) break;

		int q_size = q.size();

		for (int i = 0; i < q_size; ++i)
		{
			int cur_x = q.front().x;
			int cur_y = q.front().y;
			int cur_move = q.front().move;
			int cur_cnt = q.front().cnt;

			q.pop();
			
			for (int k = 0; k < 4; ++k)
			{
				int nx = dx[k] + cur_x;
				int ny = dy[k] + cur_y;
				int next_cnt = cur_cnt;

				if (k != cur_move) next_cnt += 1;
				if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if (map[nx][ny] == '*') continue;
				if (visit[nx][ny] == 0 || visit[nx][ny] >= next_cnt)
				{
					visit[nx][ny] = next_cnt;
					q.push({ nx,ny, k, next_cnt });
				}
			}
		}
		
	}
}
void init()
{
	cin >> m >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C')
			{
				if (start_x == 0 && start_y == 0)
				{
					start_x = i;
					start_y = j;
				}
				else
				{
					end_x = i;
					end_y = j;
				}
			}
		}
	}
}