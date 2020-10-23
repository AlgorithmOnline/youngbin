#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#define max_n 50

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
using namespace std;
int N, M, T;
int x, d, k;

void input();
void print();
void right_turn(int x, int k);
void left_turn(int x, int k);
bool bfs(int i, int j);
void update();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < T; ++i)
	{
		cin >> x >> d >> k;
		for (int i = x; i <= N; i += x) // 배수
		{
			if (d == 0) right_turn(i, k);
			else left_turn(i, k);

		}

		int check_cnt = 0;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (visit[i][j] || map[i][j] == -1) continue;
				if (bfs(i, j)) ++check_cnt;
			}
		}

		if (check_cnt == 0) //아무런 변화가 없음
		{
			update();
		}
	}

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
void update()
{
	int sum = 0;
	int temp_cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == -1) continue;
			sum += map[i][j];
			++temp_cnt;
		}
	}

	double avg = (double)sum / temp_cnt;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == -1) continue;
			if ((double)map[i][j] > avg) --map[i][j];
			else if ((double)map[i][j] < avg) ++map[i][j];
		}
	}
}
bool bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	int cnt = 1;
	int num = map[i][j];

	bool temp_visit[max_n + 1][max_n + 1];
	for (int ii = 1; ii <= N; ++ii)
	{
		for (int jj = 1; jj <= M; ++jj)
		{
			temp_visit[ii][jj] = false;
		}
	}

	temp_visit[i][j] = true;

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

			if (ny < 1) ny = M;
			if (ny > M) ny = 1;
			if (temp_visit[nx][ny]) continue;
			if (map[nx][ny] != num) continue;
			if (nx < 1 || nx > N) continue;

			++cnt;
			temp_visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	if (cnt < 2) return false;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (temp_visit[i][j]) map[i][j] = -1;
		}
	}
	return true;
}
void right_turn(int x, int k)
{
	//x행 배열을 k 칸 만큼 오른쪽으로 밀기

	k = k % M;
	if (k == 0) return;

	vector<int> temp;
	for (int i = M - k + 1; i <= M; ++i)
	{
		temp.push_back(map[x][i]);
	}
	for (int i = 1; i < M - k + 1; ++i)
	{
		temp.push_back(map[x][i]);
	}
	for (int i = 1; i <= M; ++i) map[x][i] = temp[i - 1];

	temp.clear();
}
void left_turn(int x, int k)
{
	k = k % M;
	if (k == 0) return;

	vector<int> temp;
	for (int i = k + 1; i <= M; ++i)
	{
		temp.push_back(map[x][i]);
	}
	for (int i = 1; i <= k; ++i)
	{
		temp.push_back(map[x][i]);
	}

	for (int i = 1; i <= M; ++i) map[x][i] = temp[i - 1];

	temp.clear();
}
void input()
{
	cin >> N >> M >> T;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> map[i][j];
		}
	}
}
void print()
{
	cout << "\n###\n";
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == -1) cout << 0 << ' ';
			else cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "\n###\n";
}