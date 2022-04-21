//���̵� : ���5
//���� : 11:32 - 11:49, 12:59 - 
//�� : 14:50
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[52][52];
int tmp[52][52];
vector<pair<int, int>> chicken;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int min_result = 987654321;

//r, c ��ġ���� ���� ġŲ �� ������ �ִ� �Ÿ�
//BFS�� ���ϸ� �ð��ʰ��� ���´�!!!!
int BFS(int r, int c) {
	int result = 0;
	int visited[52][52] = { 0 };
	int distance[52][52] = { 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(r, c)); //���� ��ġ ť�� push
	
	bool stop = false; //ġŲ �� ã�Ƽ� ���ߴ� flag
	visited[r][c] = 1; //�� ��ġ �湮 ǥ��
	while (!q.empty()) {
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		int cur_distance = distance[cur_r][cur_c];
		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dir[i][0];
			int next_c = cur_c + dir[i][1];
			if (next_r > 0 && next_r < N + 1 && next_c > 0 && next_c < N + 1) { //���� �΋H���� ���� ���
				if (visited[next_r][next_c] == 0) { //�湮���� ���� ���
					visited[next_r][next_c] = 1; //�湮 ó��
					distance[next_r][next_c] = cur_distance + 1;
					if (tmp[next_r][next_c] == 2) { //���� ����� ġŲ���� ã�� ���
						result = cur_distance + 1;
						//cout << result << '\n';
						stop = true;
					}
					q.push(make_pair(next_r, next_c)); //�� ����
				}
			}
		}
		if (stop) {
			break;
		}
	}
	return result;
}

//ġŲ���� 3���̹Ƿ� �ܼ� ��ǥ �Ÿ� ������ �ִ� �Ÿ� ���ϱ�
int chicken_distance(int r, int c, vector<pair<int, int>> v) {
	int result = 987654321;
	for (int i = 0; i < v.size(); i++) {
		int tmp = 0;
		tmp += abs(r - v[i].first);
		tmp += abs(c - v[i].second);
		if (result > tmp) { //�ִ� �Ÿ� ����
			result = tmp;
		}
	}
	return result;
}

//ġŲ ���� ��ġ ǥ��
vector<pair<int, int>> make_new_map(vector<pair<int, int>> v) {
	vector<pair<int, int>> house;
	//tmp�� map �����ϱ�
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c] == 2) { //���� ġŲ�� �ڸ� 0���� ����
				tmp[r][c] = 0;
			}
			else {
				tmp[r][c] = map[r][c];
			}
			if (map[r][c] == 1) {
				house.push_back(make_pair(r, c));
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		//cout << v[i].first << " " << v[i].second << '\n';
		tmp[v[i].first][v[i].second] = 2; //ġŲ�� ��ġ ǥ��
	}


	return house;
}

void DFS(int cnt, int idx, vector<pair<int, int>> v) {
	if (cnt == M) {
		//cout << v.size() << '\n';
		//for (int i = 0; i < v.size(); i++) {
		//	cout << v[i].first << " " << v[i].second << '\n';
		//}
		//cout << '\n';

		vector<pair<int, int>> house; //���� ��ġ
		int tmp_result = 0;
		house = make_new_map(v); //���� ��ġ
		/*for (int i = 0; i < house.size(); i++) {
			cout << house[i].first << " " << house[i].second << '\n';
		}
		cout << '\n';*/

		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << tmp[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/

		//���� ��ġ�� ġŲ �Ÿ� ��� ���ϱ�
		for (int i = 0; i < house.size(); i++) {
			int r = house[i].first;
			int c = house[i].second;
			tmp_result += chicken_distance(r, c, v);
		}
		if (min_result > tmp_result) { //���� ġŲ �Ÿ� �ּ� ���� ����
			min_result = tmp_result;
		}

	}
	for (int i = idx; i < chicken.size(); i++) { //��� ġŲ�� ����� �� ���ϱ�
		v.push_back(chicken[i]);
		DFS(cnt + 1, i + 1, v);
		v.pop_back();
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
			if (map[r][c] == 2) {
				chicken.push_back(make_pair(r, c));
			}
		}
	}

	vector<pair<int, int>> v;
	DFS(0, 0, v);

	//�ּ� ���� ġŲ �Ÿ� ���
	cout << min_result << '\n';


	return 0;
}