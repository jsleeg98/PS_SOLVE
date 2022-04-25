//���̵� : ���2
//���� : 17:45 - 18:24
//�� : 19:45 - 22:50
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
	int r;
	int c;
	int d;
	bool live;
	vector<int> prior[5];
};

//��� ��ȣ 1�� ����
struct Map {
	vector<int> V;
	int smell_time;
	int smell_host;
};

Map map[20][20]; //�� ����
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, -1, 1 };

int N, M, K;
int die_cnt = 0;
Shark shark[401];

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (map[r][c].V.size() != 0) {
				cout << map[r][c].V[0] << " ";
			}
			else {
				cout << "-" << " ";
			}
			
		}
		cout << '\n';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M >> K;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int shark_num;
			cin >> shark_num;
			map[r][c].smell_host = 0;
			map[r][c].smell_time = 0;
			if (shark_num != 0) {
				shark[shark_num].r = r;
				shark[shark_num].c = c;
			}
		}
	}

	for (int i = 1; i <= M ; i++) {
		int d;
		cin >> d;
		shark[i].d = d;
		shark[i].live = true;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				int d;
				cin >> d;
				shark[i].prior[j].push_back(d);
			}
		}
	}
}

//�ʿ� ���� �Ҵ�
void smell(int Time) {
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue; //������ �н�
		int r = shark[i].r;
		int c = shark[i].c;
		map[r][c].smell_host = i; //���� ���� �Ҵ�
		map[r][c].smell_time = Time + K; //������ �������� �ð�
	}
}

//��� �̵���Ű��
void move_shark(int Time) {
	//map �ʱ�ȭ
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue; //������ �н�
		map[shark[i].r][shark[i].c].V.clear(); //���� ��� ��ġ �����
	}


	//����ִ� ����� ���� ��ġ ã��
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue;//������ �н�
		int cr = shark[i].r;
		int cc = shark[i].c;
		int d = shark[i].d;
		bool check = false;
		int xr = -1;
		int xc = -1;
		int xd = -1;
		for (int j = 0; j < 4; j++) { //�켱���� ������ ã��
			int nd = shark[i].prior[d][j];
			int nr = cr + dr[nd];
			int nc = cc + dc[nd];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;//���� ����� �н�
			if (map[nr][nc].smell_time <= Time) { //��ĭ�� ã�� ���
				map[nr][nc].V.push_back(i); //�ʿ� ��� �߰�
				shark[i].r = nr;
				shark[i].c = nc;
				shark[i].d = nd;
				check = true; //üũ ǥ��
				break; //����
			}
			else if (map[nr][nc].smell_host == i) { //���� ������ ã�� ���
				if (xr == -1) {
					xr = nr;
					xc = nc;
					xd = nd;
				}
			}

		}
		if (check == false) { //��ĭ�� ��ã�� ���
			//ó������ ã�� ���� ���� ĭ���� �̵�
			shark[i].r = xr;
			shark[i].c = xc;
			shark[i].d = xd;
			map[xr][xc].V.push_back(i); //�ʿ� ��� �߰�
		}

	}
}

//��� ���̱�
void kill_shark() {
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue; //������ �н�
		int r = shark[i].r;
		int c = shark[i].c;
		if (map[r][c].V.size() > 1) { //�� ĭ�� 2���� �̻��� �� �ִ� ���
			sort(map[r][c].V.begin(), map[r][c].V.end()); //��� ��ȣ�� �������� ����
			for (int j = map[r][c].V.size() - 1; j > 0 ; j--) { //�� ������ pop�ϸ鼭 ���� ����� �� ����
				shark[map[r][c].V[j]].live = false; //����
				map[r][c].V.pop_back();//�ʿ��� ����
				die_cnt++; //���� ����� �� +1
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int time = 0;
	bool normal = false;
	while (1) {
		
		if (time >= 1000) { //1000�ʰ� ������ ����
			break;
		}
		smell(time);
		move_shark(time);
		kill_shark();
		if (M - die_cnt == 1) {
			normal = true;
			break;
		}
		time++;
		//print();
	}

	if (normal == true) {
		cout << time + 1 << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}