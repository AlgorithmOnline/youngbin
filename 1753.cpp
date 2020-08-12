#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define max_n 20000
#define INF 100000000
using namespace std;

vector<pair<int, int>> g[max_n + 1];
int dis[max_n + 1];
int start;
int v, e;

void init();
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();

	for (int i = 1; i <= v; ++i)
	{
		if (dis[i] == INF) cout << "INF\n";
		else cout << dis[i] << '\n';
	}

	return 0;
}
void solution()
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
			int sum_dis = cur_dis + next_dis;

			if (sum_dis < dis[next_node])
			{
				dis[next_node] = sum_dis;
				pq.push({-dis[next_node], next_node});
			}
		}
	}
}
void init()
{
	cin >> v >> e;
	cin >> start;

	for (int i = 1; i <= e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ b,c });
	}
}
