#include<iostream>
#define max_size 30
using namespace std;

long long dp[max_size + 1][max_size + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= max_size; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j];
		}
	}


	int T;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int n, m;

		cin >> n >> m;

		cout << dp[m][n] << '\n';
	}

	return 0;
}