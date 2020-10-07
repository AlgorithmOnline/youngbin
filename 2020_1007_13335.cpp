#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v;
int v_size;
int l, w; // l : ����  w : �ִ빫��
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
	// l ���� w ����
	queue<int >q;

	int cur_w = 0;
	int idx = 0;

	while (1)
	{
		if (q.size() == l) // ��á����
		{
			cur_w -= q.front();
			q.pop();
		}
		
		int cur_t;
		if (idx < v_size) cur_t = v[idx];
		else cur_t = 0;

		if (cur_w + cur_t <= w) // ���� �߰� �����ϸ�
		{	
			q.push(cur_t);
			cur_w += cur_t;
			++idx;
		}
		else // �ȵǸ�
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