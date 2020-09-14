
#include<iostream>
using namespace std;
int dp[41][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int t;
	cin >> n;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i < 41; ++i)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		cout << dp[t][0] << ' ' << dp[t][1] << '\n';
	}
	return 0;
}