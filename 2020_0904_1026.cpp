#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;

	cin >> N;
	vector<int> v1;
	vector<int> v2;
	int num;

	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		v1.push_back(num);
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		v2.push_back(num);
	}
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end());

	int sum = 0;

	for (int i = 0; i < N; ++i)
		sum += v1[i] * v2[i];

	cout << sum;
	return 0;
}