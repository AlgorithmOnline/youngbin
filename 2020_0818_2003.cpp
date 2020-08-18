#include<iostream>
#define max_n 10000
using namespace std;

int n, m;
int ary[max_n + 1];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> ary[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for (int j = i; j <= n; ++j)
		{
			sum += ary[j];

			if (sum > m) break;
			if (sum == m) ++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}