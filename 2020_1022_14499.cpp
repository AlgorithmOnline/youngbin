#include<iostream>
#define East 1
#define West 2
#define South 4
#define North 3
// �� y+ �� y- �� x+ �� x-
#define max_size 20
using namespace std;
int dice[6];
int M, N;
int map[max_size + 1][max_size + 1];
int x, y;
int k;
bool solution(int move);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> y >> x >> k;
	x += 1;
	y += 1;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) cin >> map[i][j];

	for (int i = 1; i <= k; ++i)
	{
		int move;
		cin >> move;
		if (solution(move)) {
			if (map[y][x] == 0) map[y][x] = dice[0];
			else {
				dice[0] = map[y][x];
				map[y][x] = 0;
			}
		}
	}

	return 0;
}
bool solution(int move)
{
	switch (move)
	{
	case East: if (x + 1 > M) return false;
			   else ++x;
		break;
	case West: if (x - 1 < 1) return false;
			   else --x;
		break;
	case South: if (y + 1 > N) return false;
				else ++y;
		break;
	case North: if (y - 1 < 1) return false;
				else --y;
		break;
	}
	// �ֻ��� ��ǥ ������ 0������ 0�̸� ä��� �ƴϸ� �״��
	int temp;
	temp = dice[0];
	switch (move)
	{
	case East: // 0:3, 3:2, 2:1, 1:0

		dice[0] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = temp;
		break; // 
	case West: // 0:1, 1:2, 2:3, 3:0

		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = temp;
		break; //
	case South: // 0:5, 5:2, 2:4, 4:0

		dice[0] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[4];
		dice[4] = temp;
		break; //
	case North: // 0:4, 4:2, 2:5, 5:0

		dice[0] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[5];
		dice[5] = temp;
		break; //
	}
	//�ֻ��� ��ǥ ������ 
	cout << dice[2] << '\n';
	// ���� �� ����ϱ�

	return true;
}