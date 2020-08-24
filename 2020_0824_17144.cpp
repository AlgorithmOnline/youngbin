#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#define max_n 50

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M, T;
int map[max_n + 2][max_n + 2];
int temp[max_n + 2][max_n + 2];
vector<pair<int, int>> air;

void spread();
void solution();
void move_up();
void move_down();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				air.push_back(make_pair(i, j));
			}
		}
	}
	solution();
	int ans = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == -1) continue;
			ans += map[i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}
void solution()
{
	for (int i = 0; i < T; ++i)
	{
		spread();
		move_up();
		move_down();
	}
}
void move_up()
{
	int x = air[0].first;
	int y = air[0].second;

	for (int i = x - 1; i > 1; --i)
	{
		map[i][y] = map[i - 1][y];
	}
	for (int i = 1; i < M; ++i)
	{
		map[1][i] = map[1][i + 1];
	}
	for (int i = 1; i < x; ++i)
	{
		map[i][M] = map[i + 1][M];
	}
	for (int i = M; i > y; --i)
	{
		map[x][i] = map[x][i - 1];
	}
	map[x][y + 1] = 0;
}
void move_down()
{
	int x = air[1].first;
	int y = air[1].second;

	for (int i = x + 1; i < N; ++i)
	{
		map[i][y] = map[i + 1][y];
	}
	for (int i = y; i < M; ++i)
	{
		map[N][i] = map[N][i + 1];
	}
	for (int i = N; i > x; --i)
	{
		map[i][M] = map[i - 1][M];
	}
	for (int i = M; i > y; --i)
	{
		map[x][i] = map[x][i - 1];
	}
	map[x][y + 1] = 0;
}
void spread()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			temp[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == -1 || map[i][j] == 0) continue;
			int count = 0;
			int sum_value = map[i][j] / 5;

			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (map[nx][ny] == -1) continue;
				if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

				++count;
				temp[nx][ny] += sum_value;
			}
			temp[i][j] += map[i][j] - sum_value * count;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			map[i][j] = temp[i][j];
		}
	}

	map[air[0].first][air[0].second] = -1;
	map[air[1].first][air[1].second] = -1;
}