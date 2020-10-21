#include <string>
#include <vector>
#include<iostream>
#define max_n 100
using namespace std;



int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	int map[max_n + 1][max_n + 1] = { 0, };
	int dp[max_n + 1][max_n + 1] = { 0, };
	int v_size = puddles.size();

	for (int i = 0; i < v_size; ++i)
	{
		int x = puddles[i][1];
		int y = puddles[i][0];
		map[x][y] = -1;
	}

	dp[1][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] == -1) dp[i][j] = 0;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}

	answer = dp[n][m];
	return answer;
}