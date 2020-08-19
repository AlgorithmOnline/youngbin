#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define max_n 50000
using namespace std;

int n, m;
int depth[max_n + 1]; 
int par[max_n + 1];
bool visit[max_n + 1];
vector<int> ans;
vector<int> g[max_n + 1];
void init();
void query(int a, int b);
void bfs();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
		
	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
void query(int a, int b)
{
	int l, h;
	if (depth[a] > depth[b])
	{
		h = a;
		l = b;
	}
	else 
	{
		h = b;
		l = a; 
	}
	while (1)
	{
		if (depth[h] == depth[l]) break;
		h = par[h];
	}

	while (1)
	{
		if (h == l) break;
		h = par[h];
		l = par[l];
	}
	ans.push_back(h);
}
void bfs()
{
	queue<pair<int, int>> q;
	int start = 1;
	visit[start] = true;
	depth[start] = 1;
	int start_size = g[start].size();
	for (int i = 0; i < start_size; ++i)
	{
		q.push({ g[start][i], 2 });
		depth[g[start][i]] = 2;
		par[g[start][i]] = 1;
		visit[g[start][i]] = true;
	}

	while (1)
	{
		if (q.empty()) break;

		int cur = q.front().first;
		int cur_depth = q.front().second;
		q.pop();

		int cur_size = g[cur].size();

		for (int i = 0; i < cur_size; ++i)
		{
			if (visit[g[cur][i]]) continue;

			visit[g[cur][i]] = true;
			depth[g[cur][i]] = cur_depth + 1;
			par[g[cur][i]] = cur;
			q.push({ g[cur][i], cur_depth + 1 });
		}
	}
}
void init()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	bfs();

	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		query(a, b);
	}
}