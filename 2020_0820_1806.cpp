#include<iostream>
#include<vector>
#include<algorithm>
#define INF 200000000
using namespace std;
int N, M;
int ans;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	ans = INF;

	int p1, p2;
	p1 = p2 = 0;
	int sum = 0;

	while (1)
	{
		if (p2 > N - 1) break;
		if (sum >= M)
		{
			if (p2 != p1)
			{
				sum -= v[p1];
				++p1;
			}
		}
		else if (M > sum)
		{

			sum += v[p2];
			++p2;
		}

		if (sum >= M)
		{
			if (ans > p2 - p1) ans = p2 - p1;
		}
	}
	while (1)
	{
		if (p1 > N - 1) break;
		sum -= v[p1];
		++p1;
		if (sum >= M)
		{
			if (p2 - p1 < ans) ans = p2 - p1;
		}
	}

	if (ans == INF) cout << 0 << '\n';
	else cout << ans << '\n';

	return 0;
}