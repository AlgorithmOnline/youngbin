#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#define max_n 100
#define INF 10000000
using namespace std;

int map[max_n + 1][max_n + 1];
int degree[max_n + 1];
int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i != j) map[i][j] = INF;
		}
	}
	int res_size = results.size();
	for (int i = 0; i < res_size; ++i)
	{
		map[results[i][0]][results[i][1]] = 1;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (map[i][j] != INF && i != j)
			{
				++degree[i];
				++degree[j];
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] == n - 1) ++answer;
	}
	return answer;
}