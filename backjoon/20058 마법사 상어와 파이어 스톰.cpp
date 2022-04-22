//���̵� : ���4
//���� : 19:10
//�� :
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N, Q;
int map[64][64];
int tmp[64][64];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int NN; // 2^N


void print_map() {
	for (int r = 0; r < pow(2, N); r++) {
		for (int c = 0; c < pow(2, N); c++) {
			cout << map[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}


void rotate_map(int x, int y, int l) {
	//�ð���� 90�� ȸ��
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			tmp[j][l - 1 - i] = map[i + x][j + y];
		}
	}

	//�� ����
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			map[i+x][j+y] = tmp[i][j];
		}
	}
}

void melt() {
	bool melt_map[64][64] = { 0 };
	for (int r = 0; r < NN; r++) {
		for (int c = 0; c < NN; c++) {
			int cnt = 0; // �ֺ� ���� ����
			for (int i = 0; i < 4; i++) {
				int nr = r + dir[i][0];
				int nc = c + dir[i][1];
				if (nr >= 0 && nr < NN && nc >= 0 && nc < NN) {
					if (map[nr][nc] > 0) { //������ ���
						cnt++; //�ֺ� ���� ���� ++
					}
				}
			}
			if (cnt < 3) { //�ֺ� ���� ������ 3 �̸��� ���
				melt_map[r][c] = true; // ���̱� �� true
			}
		}
	}

	//���̱� ���� ���̰� ���� ������ �ִ� ��� ���� ���̱�
	for (int r = 0; r < NN; r++) {
		for (int c = 0; c < NN; c++) {
			if (melt_map[r][c] == true && map[r][c] > 0) {
				map[r][c] -= 1; //���� ���̱�
			}
		}
	}
}

int BFS() {
	int maxn = 1;
	queue<pair<int, int>> q;
	int visited[64][64] = { 0 };
	for (int r = 0; r < NN; r++) {
		for (int c = 0; c < NN; c++) {
			if (map[r][c] > 0) {
				if (visited[r][c] == 0) {
					q.push(make_pair(r, c));
				}
			}
			visited[r][c] = 1;
			int cnt = 0; //��� ����
			while (!q.empty()) {
				cnt++; //��� ���� �߰�
				int cr = q.front().first;
				int cc = q.front().second;
				q.pop(); //pop
				//visited[cr][cc] = 1; //�湮 ǥ��
				for (int i = 0; i < 4; i++) { //4���⿡ ���Ͽ� �����ϴ� ������ �ִ��� ����
					int nr = cr + dir[i][0];
					int nc = cc + dir[i][1];
					if (nr >= 0 && nr < NN && nc >= 0 && nc < NN) {//���� ���� �ʴ� ���
						if (visited[nr][nc] == 0) { //�湮���� ���� ���
							if (map[nr][nc] > 0) { //������ ���
								q.push(make_pair(nr, nc)); //���� ��� ť�� �߰�
								visited[nr][nc] = 1;
							}
						}
					}
				}
				//for (int i = 0; i < NN; i++) {
				//	for (int j = 0; j < NN; j++) {
				//		cout << visited[i][j] << " ";
				//	}
				//	cout << '\n';
				//}
				//cout << '\n';
			}
			if (maxn < cnt) { //�ִ� ���� ����
				maxn = cnt;
			}
		}
	}

	return maxn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	NN = pow(2, N);
	for (int r = 0; r < NN; r++) {
		for (int c = 0; c < NN; c++) {
			cin >> map[r][c];
		}
	}

	
	for (int k = 0; k < Q; k++) {
		int L;
		cin >> L;
		//���� ������
		//���� �� ������ ��ǥ�� ���� 
		for (int i = 0; i < NN / pow(2, L); i++) {
			for (int j = 0; j < NN / pow(2, L); j++) {
				rotate_map(pow(2, L) * i, pow(2, L) * j, pow(2, L));
			}
		}
		//print_map();
		melt();
		//print_map();
	}

	int cnt = 0; 
	for (int r = 0; r < NN; r++) {
		for (int c = 0; c < NN; c++) {
			cnt += map[r][c];
		}
	}

	int result;
	result = BFS();
	if (result == 1) {
		result = 0;
	}
	
	cout << cnt << '\n' << result << '\n';


	return 0;
}