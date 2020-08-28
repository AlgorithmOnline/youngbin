#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int day;
	int time;
	int val;
} Date;
vector<Date> v;
int N;
int ans;
int v_size;
bool check[30];
void input();
void print();
void dfs(int cur_idx, int cur_score);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	v_size = v.size();

	//print();

	dfs(0, 0);
	cout << ans << '\n';

	return 0;
}
void dfs(int cur_idx, int cur_score)
{
	ans = max(ans, cur_score);
	if (cur_idx > v_size - 1)
	{
		return;
	}

	int start = v[cur_idx].day;
	int end = start + v[cur_idx].time - 1;
	int toggle = false;
	for (int i = start; i <= end; ++i)
	{
		if (check[i]) // 이미 일정이 차 있으면
		{
			toggle = true;
			break;
		}
	}
	if (!toggle)
	{
		for (int i = start; i <= end; ++i) check[i] = true; // 가능한 일정 선택
		dfs(cur_idx + 1, cur_score + v[cur_idx].val);

		for (int i = start; i <= end; ++i) check[i] = false; // 가능해도 선택 x
		dfs(cur_idx + 1, cur_score);
	}
	else
	{
		dfs(cur_idx + 1, cur_score);
	}

}
void print()
{
	for (int i = 0; i < v_size; ++i)
	{
		int day = v[i].day;
		int time = v[i].time;
		int val = v[i].val;

		cout << "day : " << day << " time : " << time << " val : " << val << '\n';
	}
}
void input()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		Date temp;
		int a, b;
		cin >> a >> b;

		if (i + a - 1 > N) continue;
		temp.day = i;
		temp.time = a;
		temp.val = b;
		v.push_back(temp);
	}
}