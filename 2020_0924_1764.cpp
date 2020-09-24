#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> v;
vector<string> answer;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	string name;

	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		v.push_back(name);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; ++i)
	{
		cin >> name;

		if (binary_search(v.begin(), v.end(), name)) answer.push_back(name);
	}

	sort(answer.begin(), answer.end());

	int size = answer.size();
	cout << size << '\n';
	for (int i = 0; i < size; ++i)
	{
		cout << answer[i] << '\n';
	}

	return 0;
}