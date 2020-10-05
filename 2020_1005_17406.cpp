#include<iostream>
#include<vector>
#include<algorithm>
#define max_n 50
#define max_k 6
using namespace std;
typedef struct {
	int r, c, s;
}area;
int map[max_n + 1][max_n + 1];
int dupli_map[max_n + 1][max_n + 1];
int n, m, k;
vector<area> v;
int ans;
int ary[max_k + 1];
void init();
void swap(int a, int b);
void permu(int cur);
void dupli_func();
void get_ans();
void print();
void turn_map(int s_x, int s_y, int e_x, int e_y);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();
	ans = 99999999;
	permu(0);

	cout << ans << '\n';
	return 0;
}
void permu(int cur)
{
	if (cur == k)
	{
		dupli_func();
		for (int i = 0; i < k; ++i)
		{
			
			int r, c, s;
			r = v[ary[i]].r;
			c = v[ary[i]].c;
			s = v[ary[i]].s;
			
			int s_x = r - s;
			int s_y = c - s;
			int e_x = r + s;
			int e_y = c + s;

			turn_map(s_x, s_y, e_x, e_y);
		}
		get_ans();
		return;
	}
	for (int i = cur; i < k; ++i)
	{
		swap(i, cur);
		permu(cur + 1);
		swap(i, cur);
	}
}
void turn_map(int s_x, int s_y, int e_x, int e_y)
{
	for (int i = 0; i < 100; ++i)
	{
		int sx = s_x + i;
		int sy = s_y + i;
		int ex = e_x - i;
		int ey = e_y - i;
		if (sx >= ex) break;
		int temp = dupli_map[sx][sy];

		for (int i = sx; i < ex; ++i)
		{
			dupli_map[i][sy] = dupli_map[i+1][sy];
		}
		for (int i = sy; i < ey; ++i)
		{
			dupli_map[ex][i] = dupli_map[ex][i+1];
		}
		for (int i = ex; i > sx; --i)
		{
			dupli_map[i][ey] = dupli_map[i-1][ey];
		}
		for (int i = ey; i > sy; --i)
		{
			dupli_map[sx][i] = dupli_map[sx][i-1];
		}
		dupli_map[sx][sy + 1] = temp;
	}
}
void get_ans()
{
	for (int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= m; ++j)
		{
			sum += dupli_map[i][j];
		}
		ans = min(sum, ans);
	}
}
void dupli_func()
{
	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dupli_map[i][j] = map[i][j];
		}
	}
}
void swap(int a, int b)
{
	int temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}
void init()
{
	cin >> n >> m >> k;

	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}
	int r, c, s;

	for (int i = 0; i < k; ++i)
	{
		ary[i] = i;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
}
void print()
{
	cout << "\n\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << dupli_map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}