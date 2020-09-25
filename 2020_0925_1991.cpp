#include<iostream>
#include<vector>
#define max_n 26
using namespace std;

vector<char> v[max_n + 1];
int n;
void pre(char ch);
void in(char ch);
void pos(char ch);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;

		for (int k = 0; k < 2; ++k)
		{
			char temp;
			cin >> temp;
			v[ch - 'A'].push_back(temp);
		}
	}

	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	pos('A');
	cout << '\n';
	return 0;
}
void pre(char ch)
{
	if (ch == '.') return;
	cout << ch;
	pre(v[ch - 'A'][0]);
	pre(v[ch - 'A'][1]);
}
void in(char ch)
{
	if (ch == '.') return;
	in(v[ch - 'A'][0]);
	cout << ch;
	in(v[ch - 'A'][1]);
}
void pos(char ch)
{
	if (ch == '.') return;
	pos(v[ch - 'A'][0]);
	pos(v[ch - 'A'][1]);
	cout << ch;
}