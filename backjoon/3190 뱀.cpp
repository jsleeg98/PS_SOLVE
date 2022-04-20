//���̵� : ���5
//���� : 10:05
//�� :
#include <iostream>
#include <queue>

using namespace std;

int map[102][102] = {0}; // map �����¿� padding
int N; // �� ũ��
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char X[10001]; //������ �ٲ�� �ð� ����

bool stop(int r, int c) {
	//���� �΋H�� ���
	if (r == N + 1 || r == 0 || c == N + 1 || c == 0) {
		return false;
	}
	//���� �΋H�� ���
	else if (map[r][c] == 1) {
		return false;
	}
	//�΋H���� ���� ���
	else{
		return true;
	}

}

int dir_change(int dir, char C) {
	if (C == 'D') {
		dir += 1;
	}
	else if (C == 'L') {
		dir -= 1;
	}

	if (dir == -1) {
		dir = 3;
	}
	else if (dir == 4) {
		dir = 0;
	}

	return dir;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	//��� ��ġ ǥ��
	int apple;
	cin >> apple;
	int r, c;
	for (int i = 0; i < apple; i++) {
		
		cin >> r >> c;
		map[r][c] = 2;
	}

	int dir_num_cnt; //���� ��ȯ Ƚ��
	cin >> dir_num_cnt;
	for (int i = 0; i < dir_num_cnt; i++) {
		int sec;
		char D;
		cin >> sec >> D;
		X[sec] = D;
	}

	queue<pair<int, int>> snake;
	snake.push(make_pair(1, 1)); //���� �� ��ġ 
	map[1][1] = 1; //���� �� ��ġ �� ǥ��
	int dir_num = 0;

	int cnt = 0;
	while (true) {
		//cout << dir_num << '\n';
		//�Ӹ� ���� ��ġ
		int head_r, head_c;
		head_r = snake.back().first;
		head_c = snake.back().second;
		//�Ӹ� �����̱�
		head_r += dir[dir_num][0];
		head_c += dir[dir_num][1];
		snake.push(make_pair(head_r, head_c)); //�Ӹ� ��ġ push
		cnt++; //�ð� �ø���
		//�΋H������ ���� Ȯ��
		if (!stop(head_r, head_c)) {
			break; //����
		}
		
		if (map[head_r][head_c] == 0) { //����� ������ pop
			map[head_r][head_c] = 1;
			map[snake.front().first][snake.front().second] = 0; //���� �����
			snake.pop(); //���� pop
		}
		else if (map[head_r][head_c] == 2) { //����� ������ �״��
			map[head_r][head_c] = 1;
		}
		
		if (X[cnt] == 'L') {
			dir_num = dir_change(dir_num, 'L');
		}
		else if (X[cnt] == 'D') {
			dir_num = dir_change(dir_num, 'D');
		}

	/*	for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				cout << map[r][c] << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
	}

	cout << cnt << '\n';

	return 0;
}