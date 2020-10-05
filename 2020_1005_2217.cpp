#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int N;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int temp;

	for (int i = 0; i < N; ++i)
	{
		temp = v[i] * (N - (i));
		ans = max(ans, temp);
	}

	cout << ans << '\n';
	return 0;
}