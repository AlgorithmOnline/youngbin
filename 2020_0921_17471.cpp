#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define max_n 10
#define INF 99999999
using namespace std;

vector<int> v[max_n + 1];
int num[max_n + 1];
int ary[max_n + 1];
bool check[max_n + 1];
bool visit[max_n + 1];
int n;
int ans;
void init();
void comb(int cur, int depth, int r);
bool vali();
void dfs(int cur);
void dfs2(int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	ans = INF;

	int len = n / 2;
	for (int i = 1; i <= n; ++i) ary[i] = i;
	
	for (int i = 1; i <= len; ++i)
	{
		comb(1, 0, i);
	}

	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
bool vali()
{
	bool res = true;
	vector<int> t1, t2;
	for (int i = 1; i <= n; ++i)
	{
		check[i] = false;
		if (visit[i]) t1.push_back(i);
		else t2.push_back(i);
	} // 팀나누기

	check[t1[0]] = true;
	dfs(t1[0]);
	int t1_size = t1.size();
	int t2_size = t2.size();

	for (int i = 0; i < t1_size; ++i)
	{
		if (check[t1[i]] == false) return false;
	}
	for (int i = 1; i <= n; ++i) check[i] = false;
	
	check[t2[0]] = true;
	dfs2(t2[0]);

	for (int i = 0; i < t2_size; ++i)
	{
		if (check[t2[i]] == false) return false;
	}

	t1.clear();
	t2.clear();
	return res;
}
void dfs2(int cur)
{
	int cur_size = v[cur].size();

	for (int i = 0; i < cur_size; ++i)
	{
		if (check[v[cur][i]] == false && visit[v[cur][i]] == false)
		{
			check[v[cur][i]] = true;
			dfs2(v[cur][i]);
		}
	}
}
void dfs(int cur)
{
	int cur_size = v[cur].size();

	for (int i = 0; i < cur_size; ++i)
	{
		if (check[v[cur][i]] == false && visit[v[cur][i]] == true)
		{
			check[v[cur][i]] = true;
			dfs(v[cur][i]);
		}
	}
}
void comb(int cur, int depth, int r)
{
	if (depth == r)
	{
		int score1 = 0, score2 = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (visit[i]) score1 += num[ary[i]];
			else score2 += num[ary[i]];
		}
		int dis = abs(score1 - score2);

		if (ans > dis) 
		{
			if (vali()) ans = dis; // 검증
		}
		return;
	}

	for(int i = cur; i <= n; ++i)
	{
		if(!visit[i])
		{
			visit[i] = true;
			comb(i, depth + 1, r);
			visit[i] = false;
		}
	}
}
void init()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> num[i];
	for (int i = 1; i <= n; ++i)
	{
		int len;
		cin >> len;
		for (int j = 1; j <= len; ++j)
		{
			int temp;
			cin >> temp;
			v[i].push_back(temp);

		}
	}
}