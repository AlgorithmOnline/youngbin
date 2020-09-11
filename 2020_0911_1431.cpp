#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> ans;

int N;

bool cmp(string a, string b);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		ans.push_back(str);
	}

	int ans_size = ans.size();

	sort(ans.begin(), ans.end(), cmp);


	for (int i = 0; i < ans_size; ++i)
		cout << ans[i] << '\n';

	return 0;
}
bool cmp(string a, string b)
{
	int a_len = a.length();
	int b_len = b.length();

	if (a_len == b_len)
	{
		int asum = 0;
		int bsum = 0;

		for (int i = 0; i < a_len; ++i)
		{
			if (a[i] >= '0' && a[i] <= '9') asum += (int)a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') bsum += (int)b[i] - '0';
		}

		if (asum < bsum) return true;
		else if (asum > bsum) return false;
		else
		{
			for (int i = 0; i < a_len; ++i)
			{
				if (a[i] == b[i]) continue;
				if (a[i] < b[i]) return true;
				else return false;
			}
		}
	}
	else if (a_len > b_len) return false;
	else return true;
}