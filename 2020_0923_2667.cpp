#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define max_size 26
using namespace std;

bool map[max_size][max_size] = { false };
int visit[max_size][max_size] = { 0, };
int N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> v;
void bfs();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char ch;
			cin >> ch;
			if (ch == '1') map[i][j] = true;
		}
	}

	bfs();


	int size = v.size();
	sort(v.begin(), v.end());
	cout << size << '\n';
	for (int i = 0; i < size; ++i)
		cout << v[i] << '\n';

	return 0;
}
void bfs()
{
	queue<pair<int, int>> q;
	int cnt;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{

			if (map[i][j] == true && visit[i][j] == 0)
			{
				cnt = 1;
				q.push(make_pair(i, j));
				visit[i][j] = 1;
				while (1) {
					if (q.empty())
					{
						v.push_back(cnt);
						break;
					}

					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; ++k)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						if (visit[nx][ny] == 1) continue;
						if (map[nx][ny] == false) continue;

						++cnt;
						q.push(make_pair(nx, ny));
						visit[nx][ny] = 1;
					}

				}
			}
		}
	}

}