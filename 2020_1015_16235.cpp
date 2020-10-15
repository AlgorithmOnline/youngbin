#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define max_n 10
using namespace std;

typedef struct {
	int x;
	int y;
	int old;
}tree;
int dx[8] = {0,0,-1,1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
int n, m, k;
int ans;
int A[max_n + 1][max_n + 1]; // 겨울에 추가 될 영양분
int cur_map[max_n + 1][max_n + 1]; // 현재 영양분
int temp_map[max_n + 1][max_n + 1]; // 봄에 죽고, 추가 될 영양분
vector<int> v[max_n + 1][max_n + 1];
void init();
void solution();
void spring();
void summer();
void fall();
void winter();
void get_ans();
void print();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
	get_ans();
	cout << ans << '\n';

	return 0;
}
void get_ans()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ans += v[i][j].size();
		}
	}
}
void solution()
{
	for (int i = 0; i < k; ++i)
	{
		spring();
		summer();
		fall();
		winter();
	}
}
void print()
{
	cout << '\n';
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << v[i][j].size() << ' ';
		}
		cout << '\n';
	}
}

void winter()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cur_map[i][j] += A[i][j];
		}
	}
}
void fall()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int v_size = v[i][j].size();
			for (int k = 0; k < v_size; ++k)
			{
				int cur_age = v[i][j][k];
				if (cur_age % 5 == 0)
				{
					for (int a = 0; a < 8; ++a)
					{
						int nx = i + dx[a];
						int ny = j + dy[a];
						if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
						v[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}
void summer()
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j =1 ; j <= n; ++j)
		{
			cur_map[i][j] += temp_map[i][j];
			temp_map[i][j] = 0;
		}
	}
}
void spring()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			sort(v[i][j].begin(), v[i][j].end());
		}
	}

	
	for (int i = 1; i <= n; ++i)
	{
		for(int j =1 ; j <= n ;++j)
		{
			int v_size = v[i][j].size();
			int temp_idx = -1;
			
			for(int k = 0; k < v_size; ++k)
			{
				int cur_age = v[i][j][k];
				
				if(cur_map[i][j] >= cur_age) //영양분 충분하면
				{
					cur_map[i][j] -= cur_age;
					++v[i][j][k]; // 나이증가
				}
				else // 부족하면
				{
					temp_idx = k;
					break;
				}
			}
		
			if (temp_idx == -1) continue;
			
			for (int k = temp_idx; k < v_size; ++k) // 죽은 영양분 추가 
			{
				temp_map[i][j] += (v[i][j][k] / 2);
			}
			
			v[i][j].erase(v[i][j].begin() + temp_idx, v[i][j].end()); // 죽은거 삭제
			
		}
	}
}
void init()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> A[i][j];
			cur_map[i][j] = 5;
		}
	}
	for(int i =1 ; i <= m; ++i)
	{
		int x, y, old;
		cin >> x >> y >> old;
		v[x][y].push_back(old);
	}
}