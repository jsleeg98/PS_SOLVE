#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//�ý� �ڷ���
struct TAXI {
	int r;
	int c;
	int gas;
};

//����� ��ġ
struct user_pos {
	int r;
	int c;
	int dst_r;
	int dst_c;
};

//��ġ �ڷ���
struct pos {
	int r;
	int c;
};

int map[21][21];
vector<user_pos> user_map[21][21];
int N, M;
TAXI taxi;
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
vector<pair<user_pos, int>> v;

//�Է�
void input() {
	cin >> N >> M;
	cin >> taxi.gas;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> map[r][c];
		}
	}
	
	cin >> taxi.r >> taxi.c;
	

	for (int i = 0; i < M; i++) {
		int user_r;
		int user_c;
		cin >> user_r >> user_c;

		int dst_r;
		int dst_c;
		cin >> dst_r >> dst_c;

		user_map[user_r][user_c].push_back({ user_r, user_c, dst_r, dst_c });
	}

}

//�Ÿ�, ��, �� �켱���� �������� ����
bool cmp_pair (pair<user_pos, int> a, pair<user_pos, int> b){
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first.r < b.first.r) {
			return true;
		}
		else if (a.first.r == b.first.r) {
			if (a.first.c < b.first.c) {
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

void BFS_1() {
	v.clear(); //�¿� �� �ִ� ����� ���� �ʱ�ȭ
	bool visited[21][21] = { 0 };
	int distance[21][21] = { 0 };
	queue<pos> q;
	q.push({ taxi.r, taxi.c });
	visited[taxi.r][taxi.c] = true;

	if (user_map[taxi.r][taxi.c].size() > 0) { //���� ��ġ���� �ٷ� �¿� �� �ִ� �°��� �ִ� ���
		v.push_back({ user_map[taxi.r][taxi.c][0], 0 });
	}

	while (!q.empty()) {
		int cr = q.front().r;
		int cc = q.front().c;
		int dist = distance[cr][cc];
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //������ ������ �н�
			if (map[nr][nc] == 1) continue; //���� �н�
			if (visited[nr][nc] == false) { //�湮���� ���� ���
				visited[nr][nc] = true;
				distance[nr][nc] = dist + 1;
				q.push({ nr, nc });
				if (user_map[nr][nc].size() > 0) {
					v.push_back({ user_map[nr][nc][0], dist + 1 }); //�¿� �� �ִ� �°��� �ִ� ���
				}
			}
		}
	}

}

//������ ������ �Ÿ�
int BFS_2(int dst_r, int dst_c) {
	int dst_distance = 0; //���������� �Ÿ�
	bool visited[21][21] = { 0 };
	int distance[21][21] = { 0 };
	queue<pos> q;
	q.push({ taxi.r, taxi.c });
	visited[taxi.r][taxi.c] = true; //�� ��ġ �湮 ó��
	while (!q.empty()) {
		int cr = q.front().r;
		int cc = q.front().c;
		int dist = distance[cr][cc];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //���� ������ �н�
			if (map[nr][nc] == 1) continue; //���� �н�
			if (visited[nr][nc] == false) { //�湮���� ���� ��� 
				visited[nr][nc] = true;
				distance[nr][nc] = dist + 1;
				q.push({ nr, nc });
				if (nr == dst_r && nc == dst_c) { //�������� ������ ���
					dst_distance = dist + 1; 
					break;
				}
			}
		}
	}

	return dst_distance;
}

bool go_user() {
	bool stop = false;
	if (v.size() == 0) { //�¿� �� �ִ� �մ��� ���� ���
		return true;
	}


	sort(v.begin(), v.end(), cmp_pair); //����

	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i].first.r << " " << v[i].first.c << " " << v[i].second << '\n';
	//}
	//cout << '\n';

	int distance = v[0].second;
	int user_r = v[0].first.r;
	int user_c = v[0].first.c;
	int dst_r = v[0].first.dst_r;
	int dst_c = v[0].first.dst_c;

	if (taxi.gas >= distance) { //����ڰ� �ִ� ������ �� �� �ִ� ���
		taxi.r = user_r;
		taxi.c = user_c;
		taxi.gas -= distance;
		user_map[user_r][user_c].pop_back(); //�մ� �¿� ���ֱ�
	}
	else { //�� �� ���� ���
		stop = true;
	}

	int dst_distance = BFS_2(dst_r, dst_c);

	if (dst_distance == 0) { //�������� �� �� ���� ���
		return true;
	}

	if (taxi.gas >= dst_distance) { //�������� �� �� �ִ� ���
		taxi.r = dst_r;
		taxi.c = dst_c;
		taxi.gas -= dst_distance;
		taxi.gas += dst_distance * 2;
	}
	else { //���� ���� ���
		stop = true;
	}

	return stop;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	bool stop;
	for (int i = 0; i < M; i++) {
		BFS_1();
		stop = go_user();
		if (stop) {
			break;
		}
	}

	if (stop) { //�ߵ��� ���� ���
		cout << -1 << '\n';
	}
	else { //�մԵ��� �� �¿��� ���
		cout << taxi.gas << '\n';
	}



	return 0;
}