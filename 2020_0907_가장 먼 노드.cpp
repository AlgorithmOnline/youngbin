#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
#define max_n 20000

using namespace std;
vector<int> g[max_n + 1];
int check[max_n + 1];
bool visit[max_n + 1];
void bfs(int cur);
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int edge_size = edge.size();
	for (int i = 0; i < edge_size; ++i)
	{
		int a = edge[i][0];
		int b = edge[i][1];

		g[a].push_back(b);
		g[b].push_back(a);
	}
	visit[1] = true;
	bfs(1);

	int h = 0;
	for (int i = 1; i <= n; ++i) { h = max(h, check[i]); }
	for (int i = 1; i <= n; ++i) { if (h == check[i]) ++answer; }


	return answer;
}
void bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	visit[cur] = true;

	while (1)
	{
		if (q.empty()) break;

		int cur = q.front();
		q.pop();

		int cur_size = g[cur].size();

		for (int i = 0; i < cur_size; ++i)
		{
			int next = g[cur][i];

			if (visit[next]) continue;
			visit[next] = true;
			check[next] = check[cur] + 1;
			q.push(next);
		}
	}
}
