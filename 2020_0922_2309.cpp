#include<iostream>
using namespace std;
int ary[9];
#include<vector>
#include<algorithm>
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;

	for (int i = 0; i < 9; ++i)
	{
		cin >> ary[i];
		result += ary[i];
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (result - ary[i] - ary[j] == 100)
			{
				ary[i] = -1;
				ary[j] = -1;
				break;
			}
		}
		if (ary[i] == -1) break;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (ary[i] != -1) v.push_back(ary[i]);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i != v.size(); ++i)
		cout << v[i] << '\n';
	return 0;
}