#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

char ary[8] = { 'A', 'C', 'F', 'J', 'M','N', 'R', 'T' };
int cnt;
vector<string> dt;
int dt_cnt;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
void permutation(int depth);
int solution(int n, vector<string> data) {
	int answer = 0;

	dt_cnt = n;
	for (int i = 0; i < n; ++i)
	{
		string temp = data[i];
		dt.push_back(temp);
	}

	permutation(0);

	answer = cnt;
	cnt = 0;
	dt.clear();
	return answer;
}
bool check_func()
{
	bool ans = true;

	for (int i = 0; i < dt_cnt; ++i)
	{
		char p1 = dt[i][0];
		char p2 = dt[i][2];
		int dis = (int)(dt[i][4] - '0');
		char compare = dt[i][3];
		int p1_num = 0;
		int p2_num = 0;

		for (int k = 0; k < 8; ++k)
		{
			if (ary[k] == p1) p1_num = k;
			if (ary[k] == p2) p2_num = k;
		}

		int check_num = abs(p1_num - p2_num) - 1;

		if (compare == '=')
		{
			if (check_num != dis)
			{
				ans = false;
				break;
			}
		}
		else if (compare == '>')
		{
			if ((check_num <= dis))
			{
				ans = false;
				break;
			}
		}
		else if (compare == '<')
		{
			if ((check_num >= dis))
			{
				ans = false;
				break;
			}
		}
	}

	return ans;
}
void swap(int a, int b)
{
	char temp;
	temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}
void permutation(int depth)
{
	if (depth == 7)
	{
		if (check_func()) ++cnt;
		return;
	}
	for (int i = depth; i < 8; ++i)
	{
		swap(i, depth);
		permutation(depth + 1);
		swap(i, depth);
	}
}