#include<iostream>

using namespace std;

int N, r, c;
int ans;
void input();
void solution(int x, int y, int n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution(1, 1, (1 << N));

	return 0;
}
void solution(int x, int y, int n)
{
	if (x == r && y == c)
	{
		cout << ans << '\n';
		return;
	}

	if (r < x + n && r >= x && c < y + n && c >= y)
	{
		solution(x, y, n / 2);
		solution(x, y + n / 2, n / 2);
		solution(x + n / 2, y, n / 2);
		solution(x + n / 2, y + n / 2, n / 2);
	}
	else ans += n * n;
}
void input()
{
	cin >> N >> r >> c;
	++r;
	++c;
}