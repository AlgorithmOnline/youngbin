#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define max_n 50
using namespace std;

vector<int> v;
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int N, M;
int K;
int ans;
void clear();
void solution(int i, int j);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;

		for (int i = 0; i < K; ++i)
		{
			int a, b;
			cin >> a >> b;
			map[a + 1][b + 1] = 1;
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (map[i][j] == 1 && visit[i][j] == false)
				{
					solution(i, j);
					++ans;
				}
			}
		}

		v.push_back(ans);
		clear();
	}

	int v_size = v.size();
	for (int i = 0; i < v_size; ++i)
		cout << v[i] << '\n';

	return 0;
}
void solution(int i, int j)
{
	queue<pair<int, int>> q;

	q.push(make_pair(i, j));
	visit[i][j] = true;
	while (1)
	{
		if (q.empty()) break;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == 0) continue;

			visit[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}

	}
}
void clear()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			map[i][j] = 0;
			visit[i][j] = false;
		}
	}
	ans = 0;
}