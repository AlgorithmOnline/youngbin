#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define max_n 8
using namespace std;
int n;
bool visit[max_n + 1];
int ary[max_n + 1];
vector<int> v;
void permu(int cur);
void swap(int a, int b);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) ary[i] = i;

	permu(1);

	int v_size = v.size();

	sort(v.begin(), v.end());

	for (int i = 0; i < v_size; ++i)
	{
		int cur_num = v[i];

		int temp = n - 1;
		for (int i = 1; i <= n; ++i)
		{
			int num = cur_num / pow(10, temp);
			cur_num -= num * pow(10, temp);
			--temp;
			cout << num << ' ';

		}
		cout << '\n';
	}

	return 0;
}
void permu(int cur)
{
	if(cur == n)
	{
		int num = 0;
		int temp = n - 1;
		for (int i = 1; i <= n; ++i)
		{
			num += ary[i]* pow(10, temp);
			--temp;
		}
		v.push_back(num);
		return;
	}

	for (int i = cur; i <= n; ++i)
	{
		swap(i, cur);
		permu(cur+1);
		swap(i, cur);
	}
}
void swap(int a, int b)
{
	int temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}
