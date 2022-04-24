//���̵� : ���3
//���� : 20:55
//�� : 21:32
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//��� ����ü
struct shark {
	int r;
	int c;
	int eat;
	int size;
};

//����� ����ü
struct fish {
	int r;
	int c;
	int distance;
};

int map[21][21]; //��
vector<fish> v_fish; //���� �� �ִ� ����� ����
int N;
shark Shark;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int Time; //�ð�

void find_fish() {
	v_fish.clear(); //���� �� �ִ� ����� ���� �ʱ�ȭ

	queue<pair<int, int>> q;
	int dist[21][21] = { 0 }; //�Ÿ� ��
	bool visited[21][21] = { 0 }; //�湮 ��

	int r = Shark.r; //��� ��ġ
	int c = Shark.c; //��� ��ġ
	visited[r][c] = true; // ����ġ �湮 ó��
	q.push({ r, c }); //ť�� �ֱ�
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		int distance = dist[cr][cc]; //���� �Ÿ�
		q.pop(); //ť pop
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //�� �Ѿ�� ���
			if (map[nr][nc] <= Shark.size) { //������ �� �ִ� ���
				if (visited[nr][nc] == false) { //�湮���� ���� ���
					dist[nr][nc] = distance + 1; //�Ÿ� ����
					visited[nr][nc] = true; //�湮 ó��
					q.push({ nr, nc }); //ť�� push
					if (map[nr][nc] < Shark.size && map[nr][nc] > 0) { //���� �� �ִ� ����� �߰�
						fish tmp;
						tmp.r = nr;
						tmp.c = nc;
						tmp.distance = distance + 1;
						v_fish.push_back(tmp); //���� �� �ִ� ����� �߰�
					}
				}
			}
		}
	}
	
}

//�Ÿ� ��, r ��, c �� �켱 ����
bool cmp_fish(fish a, fish b) {
	if (a.distance < b.distance) {
		return true;
	}
	else if (a.distance == b.distance) {
		if (a.r < b.r) {
			return true;
		}
		else if (a.r == b.r) {
			if (a.c < b.c) {
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

bool eat_fish() {
	bool stop = false;
	if (v_fish.size() == 0) { //���� �� �ִ� ����Ⱑ ���� ���
		stop = true; //����
	}
	else {
		sort(v_fish.begin(), v_fish.end(), cmp_fish); //����� ����
		int fr = v_fish[0].r;
		int fc = v_fish[0].c;
		int distance = v_fish[0].distance; //���� �� �ִ� ����� ���� �Ÿ�
		Time += distance; //�Ÿ� ��ŭ �ð� �ɸ� 1�ʿ� ��ĭ
		map[Shark.r][Shark.c] = 0;//���� �ִ��� ��ĭ ó��
		Shark.r = fr; //��� ��ġ ����
		Shark.c = fc; //��� ��ġ ����
		Shark.eat += 1; //��� ���� ������ ����
		map[fr][fc] = 9; //��� ��ġ ����
		if (Shark.eat == Shark.size) { //���� ����� ���� ũ��� ���ٸ�
			Shark.size += 1; //ũ�� +1
			Shark.eat = 0; //���� ����� �� ����
		}
	}
	return stop;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> map[r][c];
			if (map[r][c] == 9) {
				Shark.r = r;
				Shark.c = c;
				Shark.size = 2;
				Shark.eat = 0;
			}
		}
	}

	bool stop;
	while (1) {
		find_fish();
		stop = eat_fish();
		if (stop) {
			break;
		}
	}

	cout << Time << '\n';


	return 0;
}