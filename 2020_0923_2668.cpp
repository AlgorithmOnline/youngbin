#include<iostream>
#include<vector>
#include<algorithm>
#define max_n 100

using namespace std;

int ary[max_n + 1];
int N;
vector<int> v;
bool visit[max_n + 1];
void dfs(int start, int num);
void clear();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> ary[i];

	for (int i = 1; i <= N; ++i)
	{
		dfs(i, i);
		clear();
	}

	int v_size = v.size();
	sort(v.begin(), v.end());

	cout << v_size << '\n';
	for (int i = 0; i < v_size; ++i)
		cout << v[i] << '\n';

	return 0;
}
void clear()
{
	for (int i = 1; i <= N; ++i) visit[i] = false;
}
void dfs(int start, int num)
{
	if (visit[num])
	{
		if (start == num) v.push_back(start);
		return;
	}
	visit[num] = true;
	dfs(start, ary[num]);
}