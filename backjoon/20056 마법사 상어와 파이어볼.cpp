//���̵� : ���4
//���� : 21:54 - 22:14
//�� : 14:00 - 16:30
#include <iostream>
#include <queue>

using namespace std;

struct FB {
	int r;
	int c;
	int m;
	int s;
	int d;
};

int N; //�� ���� ���� ũ��
int M; //�ʱ� ���̾ ����
int K; //�̵� ��� Ƚ��


int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
vector<FB> map[51][51];
vector<FB> tmp_map[51][51];
vector<FB> fireball;

int sum_mass() {
	int total = 0;
	for (int i = 0; i < fireball.size(); i++) {
		total += fireball[i].m;
	}
	return total;
}

//���̾�� ��ġ�� �Լ�
void check_fb() {
	
	fireball.clear(); // fireball ����

	//map�� �ִ� ���̾�� ������ �������� ���̾�� ó���Ͽ�
	//fireball ���Ϳ� ����
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c].size() == 0) continue;
			else if (map[r][c].size() == 1) {
				tmp_map[r][c].push_back(map[r][c][0]); //�ӽ� �ʿ� �߰�
				fireball.push_back(map[r][c][0]); //fireball �߰�
			}
			else {
				int m = 0;
				int s = 0; 
				int d = 0;
				int cnt = map[r][c].size();
				bool even = false;
				bool odd = false;
				for (int i = 0; i < map[r][c].size(); i++) {
					m += map[r][c][i].m;
					s += map[r][c][i].s;
					if (map[r][c][i].d % 2 == 0) {
						even = true;
					}
					else {
						odd = true;
					}
				}
				m /= 5; //���� ����
				s /= cnt; //�ӵ� ����
				if (m > 0) {
					if (even && odd) {//¦Ȧ ���� ���
						for (int i = 1; i < 8; i += 2) {
							FB tmp;
							tmp.r = r;
							tmp.c = c;
							tmp.m = m;
							tmp.s = s;
							tmp.d = i;
							fireball.push_back(tmp);
						}
					}
					else {
						for (int i = 0; i < 8; i += 2) {
							FB tmp;
							tmp.r = r;
							tmp.c = c;
							tmp.m = m;
							tmp.s = s;
							tmp.d = i;
							fireball.push_back(tmp);
						}
					}
				}
			}
		}
	}
}

//���̾� �� �̵� �Լ�
void move() {

	//�� �ʱ�ȭ
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			map[r][c].clear();
		}
	}

	//���̾�� ���� ��ġ�� ������ �������� map�� �Ҵ�
	for (int i = 0; i < fireball.size(); i++) {
		int r = fireball[i].r;
		int c = fireball[i].c;
		int s = fireball[i].s;
		int d = fireball[i].d;
		int nr = r + (s % N) * dir[d][0];
		int nc = c + (s % N) * dir[d][1];
		if (nr < 1) nr += N;
		if (nr > N) nr -= N;
		if (nc < 1) nc += N;
		if (nc > N) nc -= N;

		fireball[i].r = nr;
		fireball[i].c = nc;
		map[nr][nc].push_back(fireball[i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	
	for (int i = 0; i < M; i++) {
		FB tmp;
		cin >> tmp.r >> tmp.c >> tmp.m >> tmp.s >> tmp.d;
		map[tmp.r][tmp.c].push_back(tmp);
		fireball.push_back(tmp);
	}


	while (K > 0) {
		K--;
		move();
		check_fb();
	}

	int result = sum_mass();
	cout << result << '\n';

	return 0;
}