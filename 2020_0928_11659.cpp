#include<iostream>
#include<vector>
#define max_n 100000
using namespace std;

int ary[max_n + 1];
int dp[max_n + 1];
int n, m;
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ary[i];
		dp[i] = ary[i] + dp[i - 1];
	}
	for (int i = 1; i <= m; ++i)
	{
		int s, e;
		cin >> s >> e;
		if (s == e) ans.push_back(ary[s]);
		else if (s == 1) ans.push_back(dp[e]);
		else ans.push_back(dp[e] - dp[s - 1]);
	}

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i) cout << ans[i] << '\n';

	return 0;
}