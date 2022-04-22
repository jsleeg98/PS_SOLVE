//���̵� : ���5
//���� : 16:07
//�� : 
#include <iostream>

using namespace std;
int N, M;
int map[50][50];
bool cloud[50][50];


int dir[9][2] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };



void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << map[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_cloud() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == true) {
				cout << r << " " << c << '\n';
			}
		}
	}
	cout << '\n';
}

//�� ���� �Լ�
void copy_water(int r, int c) {
	int x_dir[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
	int cnt = 0; //���� �ִ� ���� ��
	for (int i = 0; i < 4; i++) {
		int nr = r + x_dir[i][0];
		int nc = c + x_dir[i][1];
		//��踦 ������ �ʴ� ���
		if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
			if (map[nr][nc] > 0) { //���� �ִٸ�
				cnt++;
			}
		}
	}
	map[r][c] += cnt;
}

void move_cloud(int d, int s) {
	bool tmp_cloud[50][50] = {0};
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << tmp_cloud[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';

	//���� �̵�
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == true) {
				int nr = ((r + s * dir[d][0]) + (N * 30)) % N;
				int nc = ((c + s * dir[d][1]) + (N * 30)) % N;
				tmp_cloud[nr][nc] = true; //���� �̵� ����
				map[nr][nc] += 1; //�� �� 1 ����
			}
		}
	}
	//�ӽ� ���� ��ġ ����
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cloud[r][c] = tmp_cloud[r][c];
		}
	}

	//�� ����
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == true) {
				copy_water(r, c);
			}
		}
	}
	
	
	

}

//���� ���� �Լ�
void make_cloud() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == false) { //������ ���� �ʴ� ��
				if (map[r][c] >= 2) { //���� ���� 2 �̻��� ��������
					map[r][c] -= 2; //���� ���� 2 ����
					cloud[r][c] = true; //���� ����
				}
				else { //���� ����
					cloud[r][c] = false;
				}
				
			}
			else { //�׷��� ������ ���� ���� �ȵ�
				cloud[r][c] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}

	cloud[N - 1][0] = true;
	cloud[N - 1][1] = true;
	cloud[N - 2][0] = true;
	cloud[N - 2][1] = true;

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		move_cloud(d, s);
		make_cloud();
		//print();
		//print_cloud();
	}

	//���� �� ����
	int result = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			result += map[r][c];
		}
	}
	
	cout << result << '\n';


	return 0;
}