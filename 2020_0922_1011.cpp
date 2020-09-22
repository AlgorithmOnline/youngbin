#include<iostream>
using namespace std;
#include<math.h>
long long int find(long long int num);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int x, y, answer;

	for (int i = 0; i < T; ++i)
	{
		cin >> x >> y;
		if (y - x == 1) cout << "1" << "\n";
		else if (y - x == 2) cout << "2" << "\n";
		else {
			answer = find(y - x);
			cout << answer << "\n";
		}
	}

	return 0;
}
long long int find(long long int num)
{
	long long int cnt, start, end, powNum;
	long long int sqNum = sqrt(num);

	for (long long int i = sqNum;; ++i)
	{
		powNum = i * i;
		start = powNum - i + 1;
		end = powNum + i;
		if (start <= num && num <= end)
		{
			if (num > powNum) cnt = (i * 2) - 1 + 1;
			else cnt = (i * 2) - 1;
			break;
		}
	}
	return cnt;
}