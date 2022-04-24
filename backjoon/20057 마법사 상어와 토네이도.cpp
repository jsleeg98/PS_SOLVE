//���̵� : ���3
//���� : 12:40
//�� : 14:40
#include <iostream>
#include <vector>

using namespace std;

struct rate {
	int dr;
	int dc;
	float r;
};

int map[500][500];
vector<rate> t[4];
int N;
int sand_out = 0;
int dir_r[4] = { 0, 1, 0, -1 };
int dir_c[4] = { -1, 0, 1, 0 };

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << map[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void init() {
	//���� �������� �����϶��� �� ��ġ�� �ۼ�Ʈ
	rate tmp[9];
	tmp[0].dc = 0;
	tmp[0].dr = -1;
	tmp[0].r = 0.01;

	tmp[1].dr = 1;
	tmp[1].dc = 0;
	tmp[1].r = 0.01;

	tmp[2].dr = -2;
	tmp[2].dc = -1;
	tmp[2].r = 0.02;

	tmp[3].dr = -1;
	tmp[3].dc = -1;
	tmp[3].r = 0.07;

	tmp[4].dr = 1;
	tmp[4].dc = -1;
	tmp[4].r = 0.07;

	tmp[5].dr = 2;
	tmp[5].dc = -1;
	tmp[5].r = 0.02;

	tmp[6].dr = -1;
	tmp[6].dc = -2;
	tmp[6].r = 0.1;

	tmp[7].dr = 1;
	tmp[7].dc = -2;
	tmp[7].r = 0.1;

	tmp[8].dr = 0;
	tmp[8].dc = -3;
	tmp[8].r = 0.05;

	for (int i = 0; i < 4; i++) {
		//���Ϳ� �߰�
		for (int j = 0; j < 9; j++) {
			t[i].push_back(tmp[j]);
		}
		//90�� ȸ��
		for (int j = 0; j < 9; j++) {
			//�̶� dr�� ���� �����ϰ� �ٲ��ְ� ���߿� ������ dr�� dc�� �����ؾ��Ѵ�.
			//r' = -c
			//c' = r
			//�� �� 90�� ȸ���ȴ�.
			int tmp_dr = tmp[j].dr;
			tmp[j].dr = tmp[j].dc * (-1);
			tmp[j].dc = tmp_dr;
		}
	}

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < t[i].size(); j++) {
	//		cout << t[i][j].dr << " " << t[i][j].dc << " ";
	//		cout << t[i][j].r << '\n';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	
}

//���� x��ġ �·�, y��ġ ��ǥ, ���������� �޾� �� ��Ѹ���
void tonado(int xr, int xc, int yr, int yc, int dir) {
	int sand_y = map[yr][yc]; //y��ġ �𷡾�
	int spread_sand = 0; //���ư� �𷡾�
	for (int i = 0; i < 9; i++) {
		int nr = xr + t[dir][i].dr; //��������Ͽ� ������ ��ġ r
		int nc = xc + t[dir][i].dc; //��������Ͽ� ������ ��ġ c
		int sand = sand_y * t[dir][i].r; //���ư� �� ��
		spread_sand += sand; //���ư� �� �� ����
		if (nr >= N || nr < 0 || nc >= N || nc < 0) { //���� ������ ���� ���
			sand_out += sand; //���ư� �� ó��
			continue;
		}
		//���� ������ ���
		map[nr][nc] += sand; // ���ư� �� ����
	}
	int ar = yr + dir_r[dir]; //������ ��ġ
	int ac = yc + dir_c[dir];
	//���� ��ġ�� ���� ���� ���
	if (ar >= N || ar < 0 || ac >= N || ac < 0) {
		sand_out += sand_y - spread_sand;
	}
	else { //���� ��ġ�� ���� ���� ���
		map[ar][ac] += sand_y - spread_sand;
	}
	map[yr][yc] = 0; //y��ġ �� 0���� ����
}

void move_tonado(int cr, int cc) {
	int xr = cr;
	int xc = cc;
	int dir_num = 0;
	//�Ÿ� 1 ���� ó��

	int distance = 1;
	while (1) {
		for (int j = 0; j < 2; j++) { //�� ���⺰ 2���� �ݺ�
			int yr;
			int yc;
			for (int i = 0; i < distance; i++) { //�� ���⸶�� distance��ŭ ������
				yr = xr + dir_r[dir_num];
				yc = xc + dir_c[dir_num];
				tonado(xr, xc, yr, yc, dir_num); //������� ����
				//print();
				xr = yr;
				xc = yc;
			}
			
			dir_num = (dir_num + 1) % 4;//���� ��ȯ
		}
		distance++; //�Ÿ� �߰�
		if (distance == N) { 
			break;
		}
	}
	//������ ���� ������
	for (int i = 0; i < distance - 1; i++) {
		int yr = xr + dir_r[dir_num];
		int yc = xc + dir_c[dir_num];
		tonado(xr, xc, yr, yc, dir_num);
		//print();
		xr = yr;
		xc = yc;
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}

	init();
	int center = N / 2;
	move_tonado(center, center);

	cout << sand_out << '\n';


	return 0;
}