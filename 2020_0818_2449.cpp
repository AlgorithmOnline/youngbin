#include<iostream>
#include<algorithm>
#define max_n 200
#define ll long long
#define INF 100000000
using namespace std;

int n, k;
int ary[max_n + 1];
ll dp[max_n + 1][max_n + 1];

void init();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	for (int i = 1; i < n; ++i)
	{
		if (ary[i] != ary[i + 1]) dp[i][i + 1] = 1ll;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';

	for (int t = 2; t <= n; ++t)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i + t > n) break;

			dp[i][i + t] = INF;

			for (int k = 0; k < t; ++k)
			{
				ll temp = dp[i][i + k] + dp[i + k + 1][i + t];

				if (ary[i] != ary[i + k + 1])
					++temp;

				dp[i][i + t] = min(dp[i][i + t], temp);
			}
		}
	}

	cout << dp[1][n] << '\n';

	return 0;
}
void init()
{
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> ary[i];
	}
}