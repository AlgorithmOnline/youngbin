#include <string>
#include <vector>
#include<algorithm>
#include<utility>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	int routes_size = routes.size();
	vector<pair<int, int>> v;
	for (int i = 0; i < routes_size; ++i)
	{
		v.push_back({ routes[i][0], routes[i][1] });
	}
	sort(v.begin(), v.end());

	int v_size = v.size();

	int e = v[0].second;
	++answer;
	for (int i = 1; i < v_size - 1; ++i)
	{
		if (e > v[i].second) e = v[i].second;
		if (e < v[i + 1].first)
		{
			++answer;
			e = v[i + 1].second;
		}
	}
	/*
	0 35  -> - 15
	2 7 -> - 15
	6 15  -> -5
	15 17 -> -5
	*/
	return answer;
}