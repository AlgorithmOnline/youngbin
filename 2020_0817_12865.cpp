#include<iostream>
#include<algorithm>
#define max_n 100

using namespace std;

int dp[max_n*1000 + 1];
int ary[max_n + 1];
int val[max_n + 1];
int n, m;
void init();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (ary[i] <= j)
			{
				dp[j] = max(dp[j], dp[j - ary[i]] + val[i]);
			}
			
		}
	}

	cout << dp[m] << '\n';

	return 0;
}
void init()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		int w, v;
		cin >> w >> v;
		ary[i] = w;
		val[i] = v;
	}
}