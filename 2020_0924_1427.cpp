#include<iostream>
#include<string>
using namespace std;
void DownSort_Func(int *ary, int size);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	cin >> str;
	int len;

	len = str.length();

	int *ary;
	ary = new int[len];

	for (int i = 0; i < len; ++i)
	{
		ary[i] = str[i] - '0';
	}

	DownSort_Func(ary, len);
	for (int i = 0; i < len; ++i)
		cout << ary[i];
	delete[] ary;
	ary = NULL;
	return 0;
}
void DownSort_Func(int *ary, int size)
{
	int temp;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (ary[j] < ary[j + 1])
			{
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
}