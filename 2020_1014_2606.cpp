#include<iostream>
#include<vector>
#include<utility>
#define max_n 100

using namespace std;

vector<pair<int, int>> v;
int n, m;
int par[max_n + 1];
int ans;

void init();
void union_func(int a, int b);
int get_par(int cur);
void solution();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();

	for (int i = 2; i <= n; ++i)
	{
		par[i] = get_par(i);
		if (par[i] == 1) ++ans;
	}

	cout << ans << '\n';

	return 0;
}
void solution()
{
	int v_size = v.size();

	for (int i = 0; i < v_size; ++i)
	{
		int a, b;
		a = v[i].first;
		b = v[i].second;

		union_func(a, b);
	}
}
void union_func(int a, int b)
{
	int pa = get_par(a);
	int pb = get_par(b);

	if (par[pa] < par[pb])
	{
		par[pb] = pa;
	}
	else
	{
		par[pa] = pb;
	}
}
int get_par(int cur)
{
	if (cur == par[cur]) return cur;

	return get_par(par[cur]);
}
void init()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for(int i =1 ; i <= n; ++i)
	{
		par[i] = i;
	}
}