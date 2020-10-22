#include<iostream>
#include<algorithm>
#define max_n 500
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int N, M;
int ans;
void solution(int x, int y, int cnt, int sum);
void solution2(int x, int y);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			visit[i][j] = true;
			solution(i, j, 1, map[i][j]);
			visit[i][j] = false;
			solution2(i, j);
		}
	}
	cout << ans << '\n';
	return 0;
}
void solution2(int x, int y)
{
	int sum = map[x][y];
	int cnt = 1;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		++cnt;
		sum += map[nx][ny];
	}
	if (cnt < 3) return;
	else if (cnt == 3) ans = max(ans, sum);
	else { // 4°³¸é
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			ans = max(ans, sum - map[nx][ny]);
		}
	}
}
void solution(int x, int y, int cnt, int sum)
{
	if (cnt == 4)
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		if (visit[nx][ny] == false) {
			visit[nx][ny] = true;
			solution(nx, ny, cnt + 1, sum + map[nx][ny]);
			visit[nx][ny] = false;
		}
	}

}