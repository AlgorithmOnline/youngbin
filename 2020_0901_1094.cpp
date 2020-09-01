#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int X;
	int cnt = 0;
	int temp = 0;
	cin >> X;

	for (int i = 64; i >= 1; i /= 2)
	{
		if (i > X || (temp + i) > X) continue;
		temp += i;
		++cnt;
		if (temp == X) break;
	}
	cout << cnt;


	return 0;
}