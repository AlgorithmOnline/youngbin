#include<iostream>
#define max_n 8
using namespace std;

bool check[max_n + 1];
int num[max_n + 1] = { 0,1,2,3,4,5,6,7,8 };
int N, M;
void comb(int depth, int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	comb(0, 1);
	return 0;
}
void comb(int depth, int cur)
{
	if (depth == M)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (check[i]) cout << num[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = cur; i <= N; ++i)
	{
		if (!check[i]) {
			check[i] = true;
			comb(depth + 1, i);
			check[i] = false;
		}
	}
}