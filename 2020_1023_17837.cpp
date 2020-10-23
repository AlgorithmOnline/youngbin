#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#define max_n 12
using namespace std;

typedef struct
{
	int x, y, move;
}horse;
int horse_cnt;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int paper[max_n + 1][max_n + 1];
vector<pair<int, int>> map[max_n + 1][max_n + 1];
int ans;
int n;
horse horse_location[max_n + 1];
void input();
void solution();
int get_idx(int x, int y, int cur_horse);
int get_oppsite(int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();
	if (ans >= 1001) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}
void solution()
{
	// map vector�� �������, ���� ��ġ ã��
	// ���� ��ġ����, �� ��ȣ���� �ӽ� vector�� �ű��, ���� map�� vector ����
	// �� ���� �ٴ� ���� Ȯ��
	// �� : map vector�� �ӽ� vector �ű��
	// �� : ������ �ű��
	// �� or �����ʰ� : move�� �ڷ��ϰ� ��ĭ �̵� ���� �ٲ� ��or�����ʰ��̸� ����
	// �� ������ ������ ��, horse_location ����
	// ������ ������ ����� 4�̻��̴� -> ����

	bool check = false;
	while (1)
	{
		if (ans > 1000) break;

		for (int i = 1; i <= horse_cnt; ++i)
		{
			int cur_x, cur_y, cur_move;
			cur_x = horse_location[i].x;
			cur_y = horse_location[i].y;
			cur_move = horse_location[i].move;

			int cur_idx = get_idx(cur_x, cur_y, i);
			int map_size = map[cur_x][cur_y].size();

			int nx = cur_x + dx[cur_move];
			int ny = cur_y + dy[cur_move];
			int next_color;

			if (nx < 1 || ny < 1 || nx > n || ny > n) next_color = 2;
			else next_color = paper[nx][ny];

			if (next_color == 2)
			{
				cur_move = get_oppsite(cur_move);
				nx = cur_x + dx[cur_move];
				ny = cur_y + dy[cur_move];

				if (nx < 1 || ny < 1 || nx > n || ny > n) next_color = 2;
				else next_color = paper[nx][ny];

				if (next_color == 2)
				{
					map[cur_x][cur_y][cur_idx].second = cur_move;
					continue;
				}
			}

			map[cur_x][cur_y][cur_idx].second = cur_move;

			vector<pair<int, int>> temp;

			for (int j = cur_idx; j < map_size; ++j) temp.push_back(map[cur_x][cur_y][j]);
			map[cur_x][cur_y].erase(map[cur_x][cur_y].begin() + cur_idx, map[cur_x][cur_y].end());

			int temp_size = temp.size();

			if (next_color == 1) reverse(temp.begin(), temp.end());

			for (int k = 0; k < temp_size; ++k)
			{
				map[nx][ny].push_back(temp[k]);
				horse_location[temp[k].first] = { nx,ny,temp[k].second };
			}
			temp.clear();

			if (map[nx][ny].size() >= 4)
			{
				check = true;
				break;
			}
		}
		++ans;
		if (check) break;
	}
}
int get_oppsite(int cur)
{
	if (cur == 1) return 2;
	else if (cur == 2) return 1;
	else if (cur == 3) return 4;
	else if (cur == 4) return 3;
}
int get_idx(int x, int y, int cur_horse)
{
	int cur_idx = 0;
	int map_size = map[x][y].size();
	for (int j = 0; j < map_size; ++j)
	{
		if (map[x][y][j].first == cur_horse)
		{
			cur_idx = j;
			break;
		}
	}
	return cur_idx;
}
void input()
{
	cin >> n >> horse_cnt;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> paper[i][j];
		}
	}
	for (int i = 1; i <= horse_cnt; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		horse_location[i].x = a;
		horse_location[i].y = b;
		horse_location[i].move = c;
		map[a][b].push_back({ i,c }); // map�� �� ��ǥ�� ���� �߰� pair<��ȣ, ����>
	}
}