#include<iostream>
#include<vector>
#define ll long long
using namespace std;

vector<ll> ans;
ll tree[1 << 21];
int n, m, k;
int s, e, depth;
void init();
void get_depth();
void query(int a, int b);
void update(int a, int b);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	
	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
void get_depth()
{
	int temp = 1;
	depth = 1;

	while (1)
	{
		if (temp >= n) break;
		++depth;
		temp <<= 1;
	}
}
void init()
{
	cin >> n >> m >> k;
	get_depth();

	s = 1 << (depth - 1);
	e = s + n - 1;

	for (int i = s; i <= e; ++i)
	{
		cin >> tree[i];
	}
	for (int i = s - 1; i >= 1; --i)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	int size = m + k;

	for (int k = 0; k < size; ++k)
	{
		int num, a, b;
		cin >> num >> a >> b;
		
		if (num == 1)
		{
			update(a, b);
		}
		else 
		{
			query(a, b);
		}
	}
}
void update(int a, int b)
{
	int target = s + a - 1;
	int dis = b - tree[target];

	while (1)
	{
		if (target == 0) break;
		tree[target] += dis;
		target /= 2;
	}
}
void query(int a, int b)
{
	ll res = 0;
	int l = s + a - 1;
	int r = s + b - 1;

	while (1)
	{
		if (l > r) break;

		if (l % 2 == 1) res += tree[l];
		if (r % 2 == 0) res += tree[r];

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}

	ans.push_back(res);
}