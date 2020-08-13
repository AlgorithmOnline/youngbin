#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define INF 100000000
#define max_n 1000
using namespace std;

int n, m, k;
vector<pair<int, int>> g[max_n + 1];
priority_queue<int> path[max_n + 1];
void init();
void dij();
void solution();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();

	return 0;
}
void solution()
{
	dij();

	for (int i = 1; i <= n; ++i)
	{
		if (path[i].size() != k) cout << -1 << '\n';
		else cout << path[i].top() << '\n';
	}
}
void dij()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

	pq.push({ -0,1 });
	path[1].push(0);
	while (1)
	{
		if (pq.empty()) break;

		int cur_dis = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		int cur_size = g[cur].size();

		for (int i = 0; i < cur_size; ++i)
		{
			int next = g[cur][i].first;
			int next_dis = g[cur][i].second;

			if (path[next].size() < k)
			{
				path[next].push((cur_dis + next_dis));
			}
			else if ((path[next].top()) > cur_dis + next_dis)
			{
				path[next].pop();
				path[next].push((cur_dis + next_dis));
			}
			else continue;
			pq.push({ -(next_dis + cur_dis), next });
		}
	}
}
void init()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= m; ++i)
	{
		int a, b, c;

		cin >> a >> b >> c;
		g[a].push_back({ b,c });
	}
}