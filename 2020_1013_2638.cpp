#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#define max_n 100
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int check_map[max_n + 1][max_n + 1];
int map[max_n + 1][max_n + 1];
int temp_map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int n, m;
int ans;
int cur_cheese;
void init();
void print();
void solution();
void get_empty();
void visit_clear();
void check_meet();
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	while (1)
	{
		visit_clear();
		get_empty(); // ���� map�� �������� ����� ã�� visit�� �̿�
		check_meet();// map�� 1�̰�, ������� 2���̻� ������ �� ã��
		for (int i = 1; i <= n; ++i)// map 1�̰� ����� 2���̻� �����Ѱ� 0���� �����(map��) cur_cheese�� ����
		{
			for (int j = 1; j <= m; ++j)
			{
				if (map[i][j] == 1 && temp_map[i][j] == 1)
				{
					map[i][j] = 0;
					--cur_cheese;
				}
			}
		}
		
		//todo
		++ans;
		if (cur_cheese == 0) break;
	}
}
void check_meet()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			temp_map[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] == 1)
			{
				int cnt = 0;
				for (int k = 0; k < 4; ++k)
				{
					int nx = dx[k] + i;
					int ny = dy[k] + j;
					if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
					if (visit[nx][ny] == false) continue;
					if (map[nx][ny] == 1) continue;
					++cnt;
				}
				if (cnt >= 2)
				{
					temp_map[i][j] = 1;
				}
			}
		}
	}
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
void get_empty()
{
	queue<pair<int, int>> q;
	q.push({1,1});
	visit[1][1] = true;

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
			if (map[nx][ny] == 1) continue;

			visit[nx][ny] = true;
			q.push({ nx,ny });
		}

	}
}
void init()
{
	cin >> n >> m;

	for(int i =1 ; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				++cur_cheese;
			}
		}
	}
}
void print()
{
	cout << "\n====\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}