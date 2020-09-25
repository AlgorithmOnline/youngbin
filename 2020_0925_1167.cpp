#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define max_n 100000
using namespace std;
int n;
int dis_ary[max_n + 1];
vector<pair<int, int>> tree[max_n + 1];
void dfs(int cur, int dis);
int ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int cur, node, dis;

		cin >> cur;
		while (1)
		{
			cin >> node;
			if (node == -1) break;
			cin >> dis;
			tree[cur].push_back(make_pair(node, dis));
		}
	}

	dis_ary[1] = -1;

	dfs(1, 0);

	int start_node;
	int max_dis = 0;

	for (int i = 1; i <= n; ++i) {
		if (max_dis < dis_ary[i])
		{
			start_node = i;
			max_dis = dis_ary[i];
		}
	}
	for (int i = 1; i <= n; ++i) dis_ary[i] = 0;

	dis_ary[start_node] = -1;
	dfs(start_node, 0);

	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dis_ary[i]);
	}
	cout << ans << '\n';

	return 0;
}
void dfs(int cur, int dis)
{
	int len = tree[cur].size();
	for (int i = 0; i < len; ++i) {

		if (dis_ary[tree[cur][i].first] == 0) {
			dis_ary[tree[cur][i].first] = dis + tree[cur][i].second;
			dfs(tree[cur][i].first, dis + tree[cur][i].second);
		}
	}
}