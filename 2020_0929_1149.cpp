#include<iostream>
#include<algorithm>
#define max_n 1000
using namespace std;

int ary[max_n + 1][4];
int dp[max_n + 1][4];
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ary[i][1] >> ary[i][2] >> ary[i][3];
	}

	dp[1][1] = ary[1][1];
	dp[1][2] = ary[1][2];
	dp[1][3] = ary[1][3];

	for (int i = 1; i <= n; ++i)
	{
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + ary[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + ary[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + ary[i][3];
	}

	int ans = 100000000;
	for (int i = 1; i <= 3; ++i)
	{
		ans = min(ans, dp[n][i]);
	}

	cout << ans << '\n';


	return 0;
}