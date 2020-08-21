#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long >v;
int N, M;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		long long num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int first = 1;
	int second = v[N - 1];
	int mid;

	while (1)
	{
		if (first > second) break;
		long long sum = 0;

		mid = (first + second) / 2;

		for (int i = 0; i < N; ++i)
		{
			long long num = v[i] - mid;
			if (num > 0) sum += num;
		}

		if (sum >= M)
		{
			ans = mid;
			first = mid + 1;
		}
		else
		{
			second = mid - 1;
		}
	}

	cout << ans << '\n';
	return 0;
}