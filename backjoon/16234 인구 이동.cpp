//���̵� : ���5
//���� : 
//�� :
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[50][50];
int map_copy[50][50];
int visited[50][50];
int cnt; //������ ���� ��
int people; //������ ������ �α� �հ�
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int N, L, R;

//���� ���� �ٲٴ� �Լ�
void change_map(vector<pair<int, int>> coordinate) {
	int mean = people / cnt; //�α� ��� 
	for (int i = 0; i < coordinate.size(); i++) { //���� �ʿ� �ش� ��ġ�� �α� ������� ����
		map[coordinate[i].first][coordinate[i].second] = mean;
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
}

vector<pair<int, int>> BFS(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	vector<pair<int, int>> coordinate;
	visited[r][c] = 1;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		coordinate.push_back(make_pair(cr, cc));
		cnt++;
		people += map_copy[cr][cc];
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];
			if (nr >= 0 && nr < N && nc >= 0 && nc < N && visited[nr][nc] == 0) {
				int dif = abs(map_copy[nr][nc] - map_copy[cr][cc]);
				if (dif >= L && dif <= R) {
					q.push(make_pair(nr, nc));
					visited[nr][nc] = 1;
				}
			}
		}
	}

	return coordinate;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool stop = false;
	

	cin >> N >> L >> R;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c]; //map ���� ����
		}
	}
	int result = 0;
	while (1) {
		//visited �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}


		stop = true; //���� ǥ��
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				map_copy[r][c] = map[r][c]; //map_copy�� ����
			}
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				vector<pair<int, int>> coordinate; //�ٲٴ� ��ġ ���� ����
				coordinate = BFS(r, c);
				if (coordinate.size() > 1) { //�ٲٴ� ��� stop false
					stop = false;
					change_map(coordinate); //���� �� �ٲ�
				}

				cnt = 0; //���� �� �ʱ�ȭ
				people = 0; //�α� �� �ʱ�ȭ
				
			}
		}

		
		if (stop) { //���� 
			break;
		}
		result++;
	}
	
	cout << result << '\n';

	return 0;
}