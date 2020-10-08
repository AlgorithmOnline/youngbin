#include<iostream>
using namespace std;
#include<deque>
#include<string>
#include<vector>
int menu(const string str);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	int N;
	deque<int> dque;
	vector<int> v;
	int temp;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		switch (menu(str))
		{
		case 1:
			cin >> temp;
			dque.push_front(temp);
			break;
		case 2:
			cin >> temp;
			dque.push_back(temp);
			break;
		case 3:
			if (dque.empty() == 1) v.push_back(-1);
			else
			{
				v.push_back(dque.front());
				dque.pop_front();
			}
			break;
		case 4:
			if (dque.empty() == 1) v.push_back(-1);
			else
			{
				v.push_back(dque.back());
				dque.pop_back();
			}
			break;
		case 5:
			v.push_back(dque.size());
			break;
		case 6:
			v.push_back(dque.empty());
			break;
		case 7:
			if (dque.empty() == 1) v.push_back(-1);
			else v.push_back(dque.front());
			break;
		case 8:
			if (dque.empty() == 1) v.push_back(-1);
			else v.push_back(dque.back());
			break;
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << '\n';
	}
	return 0;
}
int menu(const string str)
{
	if (str.compare("push_front") == 0) return 1;
	else if (str.compare("push_back") == 0) return 2;
	else if (str.compare("pop_front") == 0) return 3;
	else if (str.compare("pop_back") == 0) return 4;
	else if (str.compare("size") == 0) return 5;
	else if (str.compare("empty") == 0) return 6;
	else if (str.compare("front") == 0) return 7;
	else if (str.compare("back") == 0) return 8;

}