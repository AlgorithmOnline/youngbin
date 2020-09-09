#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int T, N;

vector<pair<int, int>> v;
int ans;
vector<int> aa;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		ans = 0;
		++ans;

		int pv;
		pv = v[0].second;
		for (int i = 1; i < N; ++i)
		{
			if (v[i].second < pv)
			{
				++ans;
				pv = v[i].second;
			}
		}

		aa.push_back(ans);
		v.clear();
	}

	int v_size = aa.size();

	for (int i = 0; i < v_size; ++i)
		cout << aa[i] << '\n';

	return 0;
}