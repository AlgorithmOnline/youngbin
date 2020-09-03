#include<iostream>
#include<utility>
#include<string>
#include<vector>
#define max_n 8
using namespace std;

int dx[8] = { 0,0,1,-1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,1, -1,1,-1 };
pair<int, int> king;
pair<int, int> stone;
int T;
vector<string> io;

void input();
void solution();
pair<int, int> get_xy(string temp);
string get_location(pair<int, int> p);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	string king_location = get_location(king);
	string stone_location = get_location(stone);

	cout << king_location << '\n' << stone_location << '\n';
	return 0;
}
void solution()
{
	int io_size = io.size();

	for (int i = 0; i < io_size; ++i)
	{
		string temp = io[i];

		int idx = 0;
		if (temp == "R") idx = 0;
		else if (temp == "L") idx = 1;
		else if (temp == "B") idx = 2;
		else if (temp == "T") idx = 3;
		else if (temp == "RT") idx = 4;
		else if (temp == "LT") idx = 5;
		else if (temp == "RB") idx = 6;
		else if (temp == "LB") idx = 7;

		int k_nx = king.first + dx[idx];
		int k_ny = king.second + dy[idx];

		if (k_nx < 1 || k_ny < 1 || k_nx > 8 || k_ny > 8) continue;
		if (k_nx == stone.first && k_ny == stone.second)
		{
			int s_nx = stone.first + dx[idx];
			int s_ny = stone.second + dy[idx];
			if (s_nx < 1 || s_ny < 1 || s_nx > 8 || s_ny > 8) continue;
			king.first = k_nx;
			king.second = k_ny;
			stone.first = s_nx;
			stone.second = s_ny;
		}
		else
		{
			king.first = k_nx;
			king.second = k_ny;
		}
	}
}
string get_location(pair<int, int> p)
{
	string res;
	res = "";
	res += char(p.second - 1 + 'A');

	switch (p.first)
	{
	case 1: res += '8'; break;
	case 2: res += '7'; break;
	case 3: res += '6'; break;
	case 4: res += '5'; break;
	case 5: res += '4'; break;
	case 6: res += '3'; break;
	case 7: res += '2'; break;
	case 8: res += '1'; break;
	}
	return res;
}
pair<int, int> get_xy(string temp)
{
	int x, y;
	y = temp[0] - 'A' + 1;

	switch (temp[1])
	{
	case '1': x = 8; break;
	case '2': x = 7; break;
	case '3': x = 6; break;
	case '4': x = 5; break;
	case '5': x = 4; break;
	case '6': x = 3; break;
	case '7': x = 2; break;
	case '8': x = 1; break;
	}
	pair<int, int> res;
	res = { x,y };
	return res;
}
void input()
{
	string temp1, temp2;

	cin >> temp1 >> temp2 >> T;
	king = get_xy(temp1);
	stone = get_xy(temp2);

	string temp;
	for (int i = 0; i < T; ++i)
	{
		cin >> temp;
		io.push_back(temp);
	}
}