#include<iostream>
#define max_n 8
using namespace std;

bool check[max_n + 1];
int num[max_n + 1] = { 0,1,2,3,4,5,6,7,8 };
int N, M;
void comb(int depth);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	comb(0);
	return 0;
}
void comb(int depth)
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

	for (int i = 1; i <= N; ++i)
	{
		if (!check[i]) {
			check[i] = true;
			num[depth] = i;
			comb(depth + 1);
			check[i] = false;
		}
	}
}