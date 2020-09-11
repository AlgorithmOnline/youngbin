#include<iostream>
#include<algorithm>
#include<string>
#define max_n 10
using namespace std;

string str;
int ary[max_n + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;

	cin >> str;

	int len = str.length();

	for (int i = 0; i < len; ++i)
		sum += str[i] - '0';


	sort(str.begin(), str.end());
	if (str[0] == '0' && sum % 3 == 0)
	{
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
	else cout << -1 << '\n';


	return 0;
}