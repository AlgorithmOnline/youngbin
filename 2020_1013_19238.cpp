#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#define INF 999999999
#define max_n 20
using namespace std;

typedef struct {
	int dis;
	int start_x, start_y;
	int end_x, end_y;
	int start_to_end_dis;
}cus;
bool cmp(cus a, cus b)
{
	if (a.dis == b.dis)
	{
		if (a.start_x == b.start_x)
		{
			return a.start_y < b.start_y;
		}
		else return a.start_x < b.start_x;
	}
	else return a.dis < b.dis;
}
vector<cus> v;
int map[max_n + 1][max_n + 1];
int temp_map[max_n + 1][max_n + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[max_n + 1][max_n + 1];
int n, m, gas;
bool tg;
int cur_x, cur_y;
int get_dis(int s_x, int s_y, int e_x, int e_y);
void visit_clear();
void dupli();
void init();
void solution();
void bfs();
bool first_check();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	
	if (first_check())
	{
		solution();
		if (tg) cout << -1 << '\n';
		else cout << gas << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}
	return 0;
}
bool first_check()// �� ó���� ��� ������ ���� �������� �˻��ϱ�
{
	queue<pair<int, int>> q;

	dupli(); // ���� map ���
	visit_clear();
	visit[cur_x][cur_y] = true;
	q.push({ cur_x,cur_y });

	while (1)
	{
		if (q.empty()) break;
		int c_x = q.front().first;
		int c_y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = dx[k] + c_x;
			int ny = dy[k] + c_y;
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == -1) continue;

			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	int v_size = v.size();

	for (int i = 0; i < v_size; ++i)
	{
		cus cur = v[i];
		if (visit[cur.start_x][cur.start_y] == false || visit[cur.end_x][cur.end_y] == false) return false;
	}

	return true;
}
void solution()
{
	int v_size = v.size();

	int idx = 0;
	for (int i = 0; i < v_size; ++i)
	{
		bfs(); // �ýÿ��� �Ÿ�����

		sort(v.begin(), v.end(), cmp);

		cus cur = v[idx];
		int s_x, s_y, e_x, e_y, dis, to_dis;
		s_x = cur.start_x;
		s_y = cur.start_y;
		e_x = cur.end_x;
		e_y = cur.end_y;
		dis = cur.dis; // �ý�~�°��Ÿ�
		to_dis = cur.start_to_end_dis; // ����~���� �Ÿ�
		
		gas -= dis;
		if (gas < 0)
		{
			tg = true; // �߰��� �⸧ ���°��
			break;
		}
		gas -= to_dis; // �մ� ~ ������
		if (gas < 0)
		{
			tg = true;
			break;
		}
		gas += to_dis * 2; //�⸧�߰�

		cur_x = e_x;
		cur_y = e_y;

		v[idx].dis = INF;
	}
}
void bfs()
{
	queue<pair<int, int>> q;

	dupli(); // ���� map ���
	visit_clear();
	visit[cur_x][cur_y] = true;
	q.push({ cur_x,cur_y });

	while (1)
	{
		if (q.empty()) break;
		int c_x = q.front().first;
		int c_y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = dx[k] + c_x;
			int ny = dy[k] + c_y;
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == -1) continue;

			visit[nx][ny] = true;
			map[nx][ny] = map[c_x][c_y] + 1;
			q.push({ nx,ny });
		}
	}

	int v_size = v.size();

	for (int i = 0; i < v_size; ++i)
	{
		if (v[i].dis == INF) continue;
		v[i].dis = map[v[i].start_x][v[i].start_y];
	}
}
void init()
{
	cin >> n >> m >> gas;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) { map[i][j] = -1; } // ���ǻ� ���� -1�� ����
			temp_map[i][j] = map[i][j]; // �����
		}
	}

	cin >> cur_x >> cur_y;
	for (int i = 1; i <= m; ++i)
	{
		int s_x, s_y, e_x, e_y;
		cin >> s_x >> s_y >> e_x >> e_y;

		v.push_back({ 0,s_x,s_y,e_x,e_y,get_dis(s_x,s_y,e_x,e_y) });
	}
}
int get_dis(int s_x, int s_y, int e_x, int e_y)
{
	queue<pair<int, int>> q;

	dupli(); // ���� map ���
	visit_clear();
	visit[s_x][s_y] = true;
	q.push({ s_x,s_y });
	while (1)
	{
		if (q.empty()) break;
		int c_x = q.front().first;
		int c_y = q.front().second;
		q.pop();

		if (c_x == e_x && c_y == e_y) break;

		for (int k = 0; k < 4; ++k)
		{
			int nx = dx[k] + c_x;
			int ny = dy[k] + c_y;
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == -1) continue;

			visit[nx][ny] = true;
			map[nx][ny] = map[c_x][c_y] + 1;
			q.push({ nx,ny });
		}
	}
	return map[e_x][e_y];
}
void dupli()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			map[i][j] = temp_map[i][j];
		}
	}
}
void visit_clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			visit[i][j] = false;
		}
	}
}