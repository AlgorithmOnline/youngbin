#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define max_n 1000

using namespace std;

int time[max_n + 1];
int ary[max_n + 1];
int dp[max_n + 1];
vector<int> tree[max_n + 1];
int N, K, W;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		cin >> N >> K;

		for (int i = 1; i <= N; ++i) cin >> time[i];

		for (int i = 0; i < K; ++i)
		{
			int a, b;
			cin >> a >> b;
			tree[a].push_back(b);

			++ary[b];
		}
		cin >> W;

		for (int i = 1; i <= N; ++i)
		{
			dp[i] = time[i];
		}
		queue<int> q;
		for (int i = 1; i <= N; ++i)
		{
			if (ary[i] == 0)q.push(i);
		}

		while (1)
		{
			if (ary[W] == 0) break;
			if (q.empty()) break;
			int x = q.front();
			int x_size = tree[x].size();

			q.pop();

			for (int i = 0; i < x_size; ++i)
			{
				--ary[tree[x][i]];

				if (ary[tree[x][i]] == 0) {
					q.push(tree[x][i]);
				}
				dp[tree[x][i]] = max(dp[tree[x][i]], dp[x] + time[tree[x][i]]);
			}

		}

		cout << dp[W] << '\n';

		for (int i = 1; i <= N; ++i) {
			dp[i] = 0;
			tree[i].clear();
			ary[i] = 0;
		}
		while (1)
		{
			if (q.empty()) break;
			q.pop();
		}
		//dp 没家
		//q 没家
		// tree 没家
		// ary 没家
	}


	return 0;
}