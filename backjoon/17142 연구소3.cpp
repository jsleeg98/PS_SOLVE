//���̵� : ���4
//���� : 21:56
//�� :
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[50][50];
int tmp_map[50][50];
int check_map[50][50];
int N;
int M;
vector<pair<int, int>> virus;
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int result = 999999999;
int blank;


void input() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
			if (map[r][c] == 2) {
				virus.push_back({ r, c });
			}
			if (map[r][c] == 0) {
				blank++;
			}
		}
	}
}


void BFS(vector<pair<int, int>> sel_virus) {
	//tmp_map�� �� ����
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			tmp_map[r][c] = map[r][c];
			check_map[r][c] = map[r][c];
		}
	}



	////���� �ִ� ��� ���̷����� ��ĭ���� �����
	//for (int i = 0;i <  virus.size(); i++) {
	//	tmp_map[virus[i].first][virus[i].second] = 0;
	//}

	////������ ���̷��� ��ġ 2�� �����
	//for (int i = 0; i < sel_virus.size(); i++) {
	//	tmp_map[sel_virus[i].first][sel_virus[i].second] = 2;
	//}

	//print();
	int visited[50][50] = { 0 };
	int distance[50][50] = { 0 };
	queue<pair<int, int>> q;

	//ó�� ��ġ �湮 ó��
	for (int i = 0; i < sel_virus.size(); i++) {
		visited[sel_virus[i].first][sel_virus[i].second] = 1;
	}
	//ť�� ���� ��ġ �ֱ�
	for (int i = 0; i < sel_virus.size(); i++) {
		q.push({ sel_virus[i].first, sel_virus[i].second});
	}

	int infect = 0;
	int time = 0;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		int dis = distance[cr][cc];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;//�� �Ѿ�� �н�
			if (visited[nr][nc] == 1) continue;

			if (tmp_map[nr][nc] == 0 || tmp_map[nr][nc] == 2) {
				distance[nr][nc] = dis + 1; //distance�� �ð��� ���� �ǹ�
				visited[nr][nc] = 1; //�湮 ǥ��
				/*tmp_map[nr][nc] = dis + 1;*/
				if (tmp_map[nr][nc] == 0) { //���Ӱ� ���� ������ ����
					infect++; //���� ��Ų ĭ �߰�
					time = distance[nr][nc]; //�ð� ���� //�ڵ������� �� ���������� �ִ� �ð��� ����
				}
				q.push({ nr, nc }); //��ĭ�̰ų� ��Ȱ�� ���̷��� �̰ų� ť�� �߰�
			}
			//else if (tmp_map[nr][nc] == 2) {
			//	check_map[nr][nc] = 1;
			//	visited[nr][nc] = 1;
			//	distance[nr][nc] = dis;
			//	q.push({ nr, nc });
			//	//time = max(time, distance[nr][nc]);
			//	
			//}
		}
		//print();
	}
	

	
	//��� ������ ����Ų ���
	if (infect != blank) {
		time = 999999999; //�ð� ����
	}

	result = min(result, time); //�ּ� �ð��� ����� ����

	//for (int i = 0; i < sel_virus.size(); i++) {
	//	tmp_map[sel_virus[i].first][sel_virus[i].second] = 0;
	//}

	//print();
	//cout << time << '\n';
	//for (int r = 0; r < N; r++) {
	//	for (int c = 0; c < N; c++) {
	//		cout << distance[r][c] << " ";
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
}

//��� ����� �� 
void DFS(int virus_cnt, vector<pair<int, int>> sel_virus, int idx) {
	if (virus_cnt == M) { //M���� ��� �� ��� 
		BFS(sel_virus);//���� ���Ѽ� Ȯ��
		return;
	}
	//Ȱ�� ���̷��� ����� �� �ľ�
	for (int i = idx; i < virus.size(); i++) {
		sel_virus.push_back(virus[i]); //���� �ε����� Ȱ�� ���̷����� �߰� 
		DFS(virus_cnt + 1, sel_virus, i + 1); //���� ��� Ȯ��
		sel_virus.pop_back(); //���� �ε����� Ȱ�� ���̷������� ���� //�ٸ� ����� ���� ����
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	vector<pair<int, int>> tmp;
	DFS(0, tmp, 0);

	if (result == 999999999) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n';
	}

	return 0;
}