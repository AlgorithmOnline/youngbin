#include<iostream>
using namespace std;

int n;
int ans;
void dfs(int cur, int num);
int ary[20];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 11; ++i)
	{
		dfs(0, i);
		ary[i] = ans;
		ans = 0;
	}
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		int qry;
		cin >> qry;
		cout << ary[qry] << '\n';
	}
	return 0;
}
void dfs(int cur, int num)
{
	if (cur > num) return;
	if (cur == num)
	{
		++ans;
		return;
	}
	dfs(cur + 1, num);
	dfs(cur + 2, num);
	dfs(cur + 3, num);
}