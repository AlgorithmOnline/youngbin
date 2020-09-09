#include<iostream>
#include<vector>
using namespace std;

int one[8];
int two[8];
int three[8];
int four[8];

int K;
// N 0 S 1
void solution(int num, int turn);
void turn(int* ary, int turn);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char ch;

	for (int i = 0; i < 8; ++i)
	{
		cin >> ch;
		one[i] = ch - '0';
	}
	for (int i = 0; i < 8; ++i)
	{
		cin >> ch;
		two[i] = ch - '0';
	}
	for (int i = 0; i < 8; ++i)
	{
		cin >> ch;
		three[i] = ch - '0';
	}
	for (int i = 0; i < 8; ++i)
	{
		cin >> ch;
		four[i] = ch - '0';
	}

	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		int num, turn;
		cin >> num >> turn;
		solution(num, turn);
	}

	int ans = 0;

	if (one[0] == 1) ans += 1;
	if (two[0] == 1) ans += 2;
	if (three[0] == 1) ans += 4;
	if (four[0] == 1) ans += 8;


	cout << ans << '\n';

	return 0;
}
void solution(int num, int t)
{
	switch (num)
	{
	case 1:
		if (one[2] == two[6])
		{
			turn(one, t);
		}
		else
		{
			if (two[2] == three[6])
			{
				turn(one, t);
				turn(two, -t);
			}
			else
			{
				if (three[2] == four[6])
				{
					turn(one, t);
					turn(two, -t);
					turn(three, t);
				}
				else
				{
					turn(one, t);
					turn(two, -t);
					turn(three, t);
					turn(four, -t);
				}
			}
		}
		break;
	case 2:
		if (two[6] != one[2]) turn(one, -t);

		if (two[2] == three[6])
		{
			turn(two, t);
		}
		else
		{
			if (three[2] == four[6])
			{
				turn(two, t);
				turn(three, -t);
			}
			else
			{
				turn(two, t);
				turn(three, -t);
				turn(four, t);
			}
		}

		break;
	case 3:
		if (three[2] != four[6]) turn(four, -t);

		if (three[6] == two[2])
		{
			turn(three, t);
		}
		else
		{
			if (two[6] == one[2])
			{
				turn(three, t);
				turn(two, -t);
			}
			else
			{
				turn(three, t);
				turn(two, -t);
				turn(one, t);
			}
		}
		break;
	case 4:
		if (four[6] == three[2])
		{
			turn(four, t);
		}
		else
		{
			if (three[6] == two[2])
			{
				turn(four, t);
				turn(three, -t);
			}
			else
			{
				if (two[6] == one[2])
				{
					turn(four, t);
					turn(three, -t);
					turn(two, t);
				}
				else
				{
					turn(four, t);
					turn(three, -t);
					turn(two, t);
					turn(one, -t);
				}
			}
		}
		break;

	}
}
void turn(int* ary, int t)
{
	if (t == 1)
	{
		int temp;
		temp = ary[7];

		for (int i = 7; i > 0; --i)
		{
			ary[i] = ary[i - 1];
		}
		ary[0] = temp;
	}
	else if (t == -1)
	{
		int temp;
		temp = ary[0];

		for (int i = 1; i <= 7; ++i)
		{
			ary[i - 1] = ary[i];
		}
		ary[7] = temp;
	}
}