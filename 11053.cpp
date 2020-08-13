#include<iostream>
#include<algorithm>
using namespace std;

int ary[1001];
int dp[1001];
int n;
int ans;
void init();
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			if (ary[i] > ary[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, dp[i]);
	}
}
void init()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		ary[i] = num;
	}
}