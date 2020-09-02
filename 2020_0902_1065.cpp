#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cnt = 0, a, b, c;
	cin >> N;

	if (N < 100) cnt = N;
	else
	{
		cnt += 99;
		for (int i = 100; i <= N; ++i)
		{
			a = i / 100;
			b = (i - a * 100) / 10;
			c = i - (a * 100 + b * 10);
			if (b - a == c - b) ++cnt;
		}
	}
	cout << cnt;
	return 0;
}