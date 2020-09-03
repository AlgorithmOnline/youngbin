#include<iostream>
#include<algorithm>
#define max_n 10000
using namespace std;
int N, M;
int min_set, min_one;
int ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	min_set = min_one = max_n;

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		min_set = min(min_set, a);
		min_one = min(min_one, b);
	}

	ans = min_one * N;

	int temp_sum = 0;
	temp_sum = min_set * (N / 6) + min(min_one * (N % 6), min_set);

	ans = min(ans, temp_sum);
	cout << ans << '\n';

	return 0;
}