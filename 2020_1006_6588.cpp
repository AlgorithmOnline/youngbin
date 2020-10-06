#include<iostream>
#include<vector>
#include<cmath>
#define max_N 1000000
using namespace std;


bool visit[max_N + 1]; // 2~ N 까지 사용
bool check[max_N + 1];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= max_N; ++i)
	{
		if (visit[i] == false) check[i] = true;
		for (int j = i; j <= max_N; j += i)
		{
			visit[j] = true;
		}
	}

	while (1)
	{
		cin >> N;
		if (N == 0) break;

		int first = 0, second = 0;

		for (int i = 2; i <= N; ++i)
		{
			if (check[i] == true && check[N - i] == true)
			{
				if (i % 2 == 1 && (N - i) % 2 == 1) {
					first = i;
					second = N - i;
					break;
				}
			}
		}
		if (first == 0) cout << "Goldbach's conjecture is wrong.\n";
		else cout << N << " = " << first << " + " << second << '\n';

	}

	return 0;
}
