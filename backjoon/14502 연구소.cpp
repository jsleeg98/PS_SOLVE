//���̵� : ���5
//���� : 19:30
//�� : 21:43
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[8][8];
int tmp[8][8];
int N, M;
int result = 0; //�ִ� �� ����

//���̷����� ��Ʈ�� �� ��ĭ�� ã�� �Լ�
void virus_BFS() {
	int final_map[8][8];
	queue<pair<int, int>> virus;
	//���� �� ����
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			final_map[r][c] = tmp[r][c];
			if (final_map[r][c] == 2) { //���̷��� ��ġ ť�� push
				virus.push(make_pair(r, c));
			}
		}
	}

	//������, �Ʒ�, ����, ��
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	//BFS�� �̿��Ͽ� ���̷��� ��Ʈ����
	while (!virus.empty()) {
		int r = virus.front().first;
		int c = virus.front().second;
		virus.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_r = r + dir[i][0];
			int next_c = c + dir[i][1];
			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) { //���� �΋H���� ���� ���
				if (final_map[next_r][next_c] == 0) { //��ĭ�� ��쿡�� push
					final_map[next_r][next_c] = 2; //���̷��� ǥ��
					virus.push(make_pair(next_r, next_c));
				}
			}
		}

	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << final_map[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	//��ĭ ���� ����
	int empty = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (final_map[r][c] == 0) {
				empty++;
			}
		}
	}

	//�ִ� ��ĭ�� ������ result ������Ʈ
	result = max(result, empty);
}

//���� �״� �Լ��� cnt�� ������� ���� ���� ���� �ǹ��Ѵ�.
void make_wall(int cnt) {
	if (cnt == 3) { //�� 3���� ���� ���
		virus_BFS(); //���̷��� ��Ʈ���� ��ĭ ����
		
		return;
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (tmp[r][c] == 0) {
				tmp[r][c] = 1; //�� �����
				make_wall(cnt + 1); //���� �� �����
				tmp[r][c] = 0; //�� ���ֱ�
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
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (map[r][c] == 0) { //��ĭ�� ã����
				//map�� tmp�� ����
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						tmp[i][j] = map[i][j];
					}
				}

				tmp[r][c] = 1; //�� �����
				make_wall(1);  //���� �� �����
				tmp[r][c] = 0; //�� ���ֱ�
				
			}
		}
	}

	//�ִ� ��ĭ �� ���
	cout << result << '\n';

	return 0;
}