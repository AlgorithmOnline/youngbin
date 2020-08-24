#include<iostream>
#include<algorithm>
#define max_n 100
using namespace std;

typedef struct
{
	int speed, move, size;
}shark;

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
shark map[max_n + 1][max_n + 1];
shark empty_shark = { 0,0,0 };
shark moved_map[max_n + 1][max_n + 1];
int n, m;
int shark_cnt;
int ans;
void input();
int get_next_move(int cur_move);
void shark_move();
void solution();
void duplicate();
void fishing(int cur_y);
void print();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();
	cout << ans << '\n';

	return 0;
}
void solution()
{
	for (int i = 1; i <= m; ++i) // 낚시꾼 움직이는 for문 
	{
		fishing(i);
		shark_move(); // 움직이고나서
		duplicate();
	}
}
void fishing(int cur_y)
{
	for (int j = 1; j <= n; ++j) // 행
	{
		if (map[j][cur_y].size != 0)
		{
			ans += map[j][cur_y].size;
			map[j][cur_y] = empty_shark;
			break;
		}
	}
}
void duplicate()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			map[i][j] = moved_map[i][j];
			moved_map[i][j] = empty_shark;
		}
	}
}
void shark_move()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j].size == 0) continue;
			int cur_speed = map[i][j].speed;
			int cur_move = map[i][j].move;
			int cur_size = map[i][j].size;
			int nx = i;
			int ny = j;
			int temp_speed;
			if (cur_move == 1 || cur_move == 2) temp_speed = n;
			else temp_speed = m;
			temp_speed *= 2;
			temp_speed -= 2;
			temp_speed = cur_speed % temp_speed;
			for (int t = 0; t < temp_speed; ++t)
			{
				if (nx == 1 && cur_move == 1) cur_move = 2;
				if (nx == n && cur_move == 2) cur_move = 1;
				if (ny == 1 && cur_move == 4) cur_move = 3;
				if (ny == m && cur_move == 3) cur_move = 4;
				switch (cur_move)
				{
				case 1: --nx;
					break;
				case 2: ++nx;
					break;
				case 3: ++ny;
					break;
				case 4: --ny;
					break;
				}
			}
			if (moved_map[nx][ny].size > cur_size) continue;
			shark temp;
			temp.speed = cur_speed;
			temp.size = cur_size;
			temp.move = cur_move;
			moved_map[nx][ny] = temp;
		}
	}
}
int get_next_move(int cur_move)
{
	if (cur_move == 1) return 2;
	else if (cur_move == 2) return 1;
	else if (cur_move == 3) return 4;
	else return 3;
}
void input()
{
	cin >> n >> m >> shark_cnt;
	for (int i = 1; i <= shark_cnt; ++i)
	{
		int x, y, speed, move, size;
		cin >> x >> y >> speed >> move >> size;
		shark temp;
		temp.speed = speed;
		temp.move = move;
		temp.size = size;
		map[x][y] = temp;
	}
}