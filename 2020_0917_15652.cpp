#include<iostream>
#include<vector>
using namespace std;

int N, M;
void dfs(int depth);
vector<int> temp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	dfs(0);

	return 0;
}
void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << temp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (temp.size() != 0 && temp.back() > i) continue;

		temp.push_back(i);
		dfs(depth + 1);
		temp.pop_back();
	}
}