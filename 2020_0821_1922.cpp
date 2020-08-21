#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#define max_n 1000
using namespace std;
typedef struct {
	int a;
	int b;
	int dis;
}g;
int n, m;
vector<g> v;
int ans;
int ary[max_n + 1];

void input();
void solution();
int get_par(int cur);
void union_func(int a, int b);
bool query_func(int a, int b);
bool cmp(g a, g b);

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
	for (int i = 1; i <= n; ++i) ary[i] = i;
	sort(v.begin(), v.end(), cmp);

	int v_size = v.size();

	for (int i = 0; i < v_size; ++i)
	{
		int a, b, dis;
		a = v[i].a;
		b = v[i].b;
		dis = v[i].dis;

		if (query_func(a, b)) continue;

		union_func(a, b);
		ans += dis;
	}
}
bool cmp(g a, g b)
{
	return a.dis < b.dis;
}
bool query_func(int a, int b)
{
	int pa = get_par(a);
	int pb = get_par(b);

	if (pa == pb) return true;
	else return false;
}
void union_func(int a, int b)
{
	int pa = get_par(a);
	int pb = get_par(b);

	if (pa < pb) ary[pb] = pa;
	else ary[pa] = pb;
}
int get_par(int cur)
{
	if (cur == ary[cur]) return cur;

	return ary[cur] = get_par(ary[cur]);
}
void input()
{
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
}