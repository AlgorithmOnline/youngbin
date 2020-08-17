#include<iostream>
#include<algorithm>
#define max_n 100
using namespace std;

int ary[max_n + 1];
int cost[max_n + 1];
int dp[max_n * max_n + 1];
int n;
int m;
int sum;

void init();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = sum; j >= cost[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - cost[i]] + ary[i]);
		}
	}

	int ans = 0;

	for (int i = 1; i <= sum; ++i)
	{
		if(dp[i] >= m) 
		{
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
void init()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ary[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
		sum += cost[i];
	}
}