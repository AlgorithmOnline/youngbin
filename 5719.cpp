#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define max_n 20000
#define INF 100000000
using namespace std;

vector<pair<int, int>> g[max_n + 1];
vector<pair<int, int>> g2[max_n + 1];

vector<int> ans;
int dis[max_n + 1];
int start;
int e;
int v, edge;
int short_dis;
void init();
void bfs();
void dij();
void clear_func();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	
	int ans_size = ans.size();

	for(int i = 0; i < ans_size; ++i)
	{
		if (ans[i] == INF) cout << -1 << '\n';
		else cout << ans[i] << '\n';
	}
	return 0;
}
void bfs()
{
	queue<pair<int, int>> q;

	q.push({ e, short_dis });

	while (1)
	{
		if (q.empty()) break;

		int cur = q.front().first;
		int cur_dis = q.front().second;
		q.pop();

		int cur_size = g2[cur].size();

		for (int i = 0; i < cur_size; ++i)
		{
			int next = g2[cur][i].first;
			int next_dis = g2[cur][i].second;

			if (cur_dis - next_dis == dis[next])
			{
				int temp_size = g[next].size();

				for (int k = 0; k < temp_size; ++k)
				{
					int cur2 = g[next][k].first;

					if (cur2 == cur)
					{
						g[next][k].second = -1;
						break;
					}
				}

				q.push({ next,cur_dis - next_dis });
			}
		}
	}

}
void dij()
{
	for (int i = 1; i <= v; ++i) dis[i] = INF;
	dis[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

	int start_size = g[start].size();

	pq.push({ 0, start });

	while (1)
	{
		if (pq.empty()) break;

		int cur_node = pq.top().second;
		int cur_dis = -pq.top().first;
		int cur_size = g[cur_node].size();
		pq.pop();

		if (cur_dis > dis[cur_node]) continue;
		for (int i = 0; i < cur_size; ++i)
		{
			int next_node = g[cur_node][i].first;
			int next_dis = g[cur_node][i].second;

			if (next_dis == -1) continue;

			int sum_dis = cur_dis + next_dis;

			if (sum_dis < dis[next_node])
			{
				dis[next_node] = sum_dis;
				pq.push({ -dis[next_node], next_node });
			}
		}
	}
}
void init()
{
	while (1)
	{
		cin >> v >> edge;
		if (v == 0 && edge == 0) break;

		cin >> start >> e;
		++start;
		++e;
		
		for (int i = 1; i <= edge; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			++a;
			++b;

			g[a].push_back({ b,c });
			g2[b].push_back({ a,c });
		}

		for (int i = 1; i <= v; ++i) dis[i] = INF;
		dis[start] = 0;

		dij();
		short_dis = dis[e];

		bfs();

		dij();

		ans.push_back(dis[e]);

		clear_func();
	}
	
}
void clear_func()
{
	for (int i = 1; i <= v; ++i)
	{
		g[i].clear();
		g2[i].clear();
	}
}