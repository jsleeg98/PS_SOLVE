//���̵� : ���2
//���� : 19:26
//�� : 20:41
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;


struct block {
	int size;
	int rainbow;
	int r;
	int c;
	vector<pair<int, int>> blocks;
};
int N, M;
int map[21][21];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
vector<block> v;
int result;

void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << map[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool cmp_block(block a, block b) {
	if (a.size > b.size) {
		return true;
	}
	else if (a.size == b.size) {
		if (a.rainbow > b.rainbow) {
			return true;
		}
		else if (a.rainbow == b.rainbow) {
			if (a.r > b.r) {
				return true;
			}
			else if (a.r == b.r) {
				if (a.c > b.c) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void find_group() {
	v.clear(); //��ϱ׷� ���� �ʱ�ȭ
	
	queue<pair<int, int>> q;
	bool visited[21][21] = { 0 };

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int m;
			int size = 0;
			int rainbow = 0; //������ ��� ����
			vector<pair<int, int>> rainbow_v;
			block tmp;
			if (map[r][c] >= 1 && map[r][c] <= M && visited[r][c] == false) { //�Ϲ� ����̰� �湮���� ���� ���
				m = map[r][c]; //��� ��ȣ ����
				q.push({ r, c }); //ť�� push
				visited[r][c] = true; //�湮 ó��
				size++; //������ +1
				tmp.blocks.push_back({ r, c }); //block �׷쿡 ���� ����� ��ġ �߰�
				while (!q.empty()) { //ť�� ��������
					int cr = q.front().first;
					int cc = q.front().second;
					q.pop(); //ť���� pop
					for (int i = 0; i < 4; i++) {
						int nr = cr + dr[i];
						int nc = cc + dc[i];
						if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //������ �Ѿ�� �н�
						if (map[nr][nc] == m || map[nr][nc] == 0){ //���� ����̰ų� ������ ����϶���
							if (visited[nr][nc] == false) { //�湮���� ���� ��츸 ����
								tmp.blocks.push_back({ nr, nc }); //block �׷쿡 ���� ����� ��ġ �߰�
								q.push({ nr, nc }); //ť�� push
								visited[nr][nc] = true; //�湮 ó��
								size++; //������ +1
								if (map[nr][nc] == 0) { //����������� ���
									rainbow++; //������ ��� +1
									//visited[nr][nc] = false; //������ ����� �ٸ� ����� �湮�� �� �ֱ� ������ �ٽ� �̹湮 ó���ؾ���
									rainbow_v.push_back({ nr, nc });
								}
							}
						}
					}
				}
				//�� ��� �׷쿡�� ����� ������ ����� �ٽ� �̹湮 ó���� �Ͽ�
				//�ٸ� ��� �׷� ���� �� ����� �� �ֵ��� �Ѵ�.
				for (int i = 0; i < rainbow_v.size(); i++) {
					visited[rainbow_v[i].first][rainbow_v[i].second] = false;
				}
				if (size > 1) { // ��� ������ 2�� �̻��� ����
					tmp.r = r;
					tmp.c = c;
					tmp.size = size;
					tmp.rainbow = rainbow;
					v.push_back(tmp); // ��� �׷� �߰�
				}
			}
		}
	}
}

//���� ��� �Լ�
bool score() {
	bool stop = false;
	if (v.size() == 0) { //��� �׷��� ���� ���
		stop = true; //����
	}
	else {
		sort(v.begin(), v.end(), cmp_block); //����
		result += pow(v[0].size, 2);
		//cout << result << '\n';
		vector<pair<int, int>> pos_v = v[0].blocks;
		for (int i = 0; i < pos_v.size(); i++) {
			map[pos_v[i].first][pos_v[i].second] = -2; //���� ��� ó��
		}
	}
	return stop;
}

//��� ���� ������ �Լ�
void down(int r, int c) {
	if (r + 1 == N + 1 || map[r+1][c] == -1) { //���� ����� ������ ����̳� �̹� �� ���� ���
		return; //����
	}
	if (map[r + 1][c] == -2) { //��ĭ�� ��쿡�� �����Ⱑ��
		map[r + 1][c] = map[r][c]; //��� 1ĭ ������
		map[r][c] = -2; //��ĭ ó��
		down(r + 1, c);//����� ����
	}
	
}

//�߷� �Լ�
void gravity() {
	for (int r = N; r >= 1; r--) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c] == -1) continue; //������ ����� �н�
			down(r, c);
		}
	}
}

//�ݽð� ȸ�� �Լ�
void rotate() {
	int tmp_map[21][21] = { 0 };
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int nr = N + 1 - c;
			int nc = r;
			tmp_map[nr][nc] = map[r][c]; //������ �ӽ� �ʿ� ����
		}
	}
	
	//map�� �ű��
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			map[r][c] = tmp_map[r][c];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> map[r][c];
		}
	}

	bool stop = false;
	while (1) {
		find_group();
		stop = score();
		if (stop) {
			break;
		}
		//print();
		gravity();
		//print();
		rotate();
		//print();
		gravity();
		//print();
	}

	cout << result << '\n';

	return 0;
}