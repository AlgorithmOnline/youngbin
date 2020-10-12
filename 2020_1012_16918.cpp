#include<iostream>
#include<queue>
#include<utility>
#define max_n 200
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char map[max_n + 1][max_n + 1];
char map2[max_n + 1][max_n + 1];
int n, m, t;
vector<pair<int, int>>v1, v2;

void init();
void print();
void bomb_func(int num);
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();	

	solution();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}
void solution()
{
	//초기 v1에 폭탄
	int cur = 1; // 1일때 v1 // 2일때 v2
	for (int i = 1; i <= t; ++i)
	{
		if (i == 1) continue;
		if (i % 2 == 0) // 설치
		{
			if (cur == 1)
			{
				
				for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= m; ++j)
					{
						if (map[i][j] == '.')
						{
							v2.push_back({ i,j });
							map[i][j] = 'O';
						}
					}
				}
			}
			else if(cur == 2)
			{
				
				for (int i = 1; i <= n; ++i)
				{
					for (int j = 1; j <= m; ++j)
					{
						if (map[i][j] == '.')
						{
							v1.push_back({ i,j });
							map[i][j] = 'O';
						}
					}
				}
			
			}
		}
		else if (i % 2 == 1) //터트리기
		{
			if (cur == 1)
			{
				bomb_func(cur);
				cur = 2;
			}
			else if(cur == 2)
			{
				bomb_func(cur);
				cur = 1;
			}
		}
	}
}
void bomb_func(int num)
{
	queue<pair<int, int>> q;

	if (num == 1)
	{
		int v_size = v1.size();
		for (int i = 0; i < v_size; ++i)
		{
			q.push(v1[i]);
		}
		v1.clear();
	}
	else
	{
		int v_size = v2.size();
		for (int i = 0; i < v_size; ++i)
		{
			q.push(v2[i]);
		}
		v2.clear();
	}

	while(1)
	{
		if (q.empty()) break;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		map[cur_x][cur_y] = '.';
		for (int k = 0; k < 4; ++k)
		{
			int nx = cur_x + dx[k];
			int ny = cur_y + dy[k];

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			map[nx][ny] = '.';
		}
	}
	if (num == 1)
	{
		v2.clear();
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (map[i][j] == 'O') v2.push_back({ i,j });
			}
		}
	}
	else
	{
		v1.clear();
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (map[i][j] == 'O') v1.push_back({ i,j });
			}
		}
	}
}
void print()
{
	cout << "\n===\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}
void init()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'O') v1.push_back({ i,j });
		}
	}
}