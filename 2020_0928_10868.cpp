#include<iostream>
#include<algorithm>
using namespace std;

int g[1 << 21];
int N, M;
int s, e;
void init();
int find_ans(int a, int b);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int temp = 1;
	int level = 1;
	while (1)
	{
		if (temp >= N) break;
		temp <<= 1;
		++level;
	}
	s = 1 << (level - 1);
	e = s + N;

	init();

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << find_ans(a, b) << '\n';
	}
	return 0;
}
int find_ans(int a, int b)
{
	int l = a + s - 1;
	int r = b + s - 1;
	int ans = 1000000001;

	while (1)
	{
		if (l > r) break;
		if (l % 2 == 1) ans = min(ans, g[l]);
		if (r % 2 == 0) ans = min(ans, g[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}
void init()
{
	for (int i = s; i < e; ++i)
	{
		cin >> g[i];
	}

	for (int i = s - 1; i > 0; --i)
	{
		g[i] = min(g[i * 2], g[i * 2 + 1]);
	}
}