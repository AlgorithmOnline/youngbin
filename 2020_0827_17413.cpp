#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, str);

	string ans = "";

	bool check = false;
	string temp = "";
	str += '!';

	int str_size = str.length();
	for (int i = 0; i < str_size; ++i)
	{
		if (str[i] == '<')
		{
			if (temp.length() != 0) 
			{
				reverse(temp.begin(), temp.end());
				ans += temp;
				temp = "";
			}
			for (int k = i; k < str_size; ++k)
			{
				temp += str[k];
				if (str[k] == '>')
				{
					ans += temp;
					temp = "";
					i = k;
					break;
				}
			}
			continue;
		}
		if (str[i] == ' ' || str[i] == '!')
		{
			if (temp.length() != 0)
			{
				reverse(temp.begin(), temp.end());
				ans += temp;
				temp = "";
			}
			if (str[i] == ' ') ans += ' ';
			continue;
		}
		temp += str[i];
	}

	cout << ans << '\n';
	return 0;
}