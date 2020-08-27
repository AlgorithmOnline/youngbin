#include<iostream>
#include<string>
using namespace std;

string s;
int s_size, p_size;
int num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	cin >> num;

	int ans = 0;

	for (int i = 1; i <= num; ++i)
	{
		string str;
		cin >> str;
		str += str;

		if (str.find(s) != string::npos) ++ans;
	}

	cout << ans << '\n';

	return 0;
}