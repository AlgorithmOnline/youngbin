#include<iostream>
#include<algorithm>
#define max_n 50
using namespace std;

int N, M;
int ans;
int map[max_n + 1][max_n + 1];
int check_map1[9][9];
int check_map2[9][9];
void print();
void input();
void fill_cmap();
int check_draw(int x_start, int y_start);
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	fill_cmap();

	ans = 100;

	solution();

	cout << ans << '\n';
	//print();

	return 0;
}
void solution()
{
	for (int i = 1; i <= N; ++i)
	{
		int x_start = i;
		int x_end = i + 7;
		if (x_end > N) continue;
		for (int j = 1; j <= M; ++j)
		{
			int y_start = j;
			int y_end = j + 7;
			if (y_end > M) break;
			ans = min(check_draw(x_start, y_start), ans);
		}
	}
}
int check_draw(int x_start, int y_start)
{
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 1; i <= 8; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			if (check_map1[i][j] != map[x_start + i - 1][y_start + j - 1]) ++cnt1;
			if (check_map2[i][j] != map[x_start + i - 1][y_start + j - 1]) ++cnt2;
		}
	}

	return min(cnt1, cnt2);
}
void fill_cmap()
{
	check_map1[1][1] = 1;
	check_map1[1][3] = 1;
	check_map1[1][5] = 1;
	check_map1[1][7] = 1;
	check_map1[2][2] = 1;
	check_map1[2][4] = 1;
	check_map1[2][6] = 1;
	check_map1[2][8] = 1;
	check_map1[3][1] = 1;
	check_map1[3][3] = 1;
	check_map1[3][5] = 1;
	check_map1[3][7] = 1;
	check_map1[4][2] = 1;
	check_map1[4][4] = 1;
	check_map1[4][6] = 1;
	check_map1[4][8] = 1;
	check_map1[5][1] = 1;
	check_map1[5][3] = 1;
	check_map1[5][5] = 1;
	check_map1[5][7] = 1;
	check_map1[6][2] = 1;
	check_map1[6][4] = 1;
	check_map1[6][6] = 1;
	check_map1[6][8] = 1;
	check_map1[7][1] = 1;
	check_map1[7][3] = 1;
	check_map1[7][5] = 1;
	check_map1[7][7] = 1;
	check_map1[8][2] = 1;
	check_map1[8][4] = 1;
	check_map1[8][6] = 1;
	check_map1[8][8] = 1;

	check_map2[2][1] = 1;
	check_map2[2][3] = 1;
	check_map2[2][5] = 1;
	check_map2[2][7] = 1;
	check_map2[1][2] = 1;
	check_map2[1][4] = 1;
	check_map2[1][6] = 1;
	check_map2[1][8] = 1;
	check_map2[4][1] = 1;
	check_map2[4][3] = 1;
	check_map2[4][5] = 1;
	check_map2[4][7] = 1;
	check_map2[3][2] = 1;
	check_map2[3][4] = 1;
	check_map2[3][6] = 1;
	check_map2[3][8] = 1;
	check_map2[6][1] = 1;
	check_map2[6][3] = 1;
	check_map2[6][5] = 1;
	check_map2[6][7] = 1;
	check_map2[5][2] = 1;
	check_map2[5][4] = 1;
	check_map2[5][6] = 1;
	check_map2[5][8] = 1;
	check_map2[7][2] = 1;
	check_map2[7][4] = 1;
	check_map2[7][6] = 1;
	check_map2[7][8] = 1;
	check_map2[8][1] = 1;
	check_map2[8][3] = 1;
	check_map2[8][5] = 1;
	check_map2[8][7] = 1;


}
void print()
{
	cout << '\n';
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void input()
{
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			char ch;
			cin >> ch;
			if (ch == 'W') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
}