#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v;
int v_size;
int l, w; // l : 길이  w : 최대무게
int ans;
void init();
void solution();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	solution();
	
	cout << ans << '\n';

	return 0;
}
void solution()
{
	// l 길이 w 무게
	queue<int >q;

	int cur_w = 0;
	int idx = 0;

	while (1)
	{
		if (q.size() == l) // 꽉찼으면
		{
			cur_w -= q.front();
			q.pop();
		}
		
		int cur_t;
		if (idx < v_size) cur_t = v[idx];
		else cur_t = 0;

		if (cur_w + cur_t <= w) // 무게 추가 가능하면
		{	
			q.push(cur_t);
			cur_w += cur_t;
			++idx;
		}
		else // 안되면
		{
			q.push(0);
		}
		++ans;
		if (cur_w == 0) break;
	}
}
void init()
{
	cin >> v_size >> l >> w;
	for (int i = 0; i < v_size; ++i)
	{
		int weight;
		cin >> weight;
		v.push_back(weight);
	}
}