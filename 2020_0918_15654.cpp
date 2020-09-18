#include<iostream>
#include<vector>
#include<algorithm>
#define max_n 8
using namespace std;

bool visit[max_n + 1];
int N, M;
int num[max_n + 1];
vector<int> v;

void dfs(int depth);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	dfs(0);
	v.clear();
	return 0;
}
void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << num[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (!visit[i])
		{
			visit[i] = true;
			num[depth] = v[i];
			dfs(depth + 1);
			visit[i] = false;
		}
	}
}