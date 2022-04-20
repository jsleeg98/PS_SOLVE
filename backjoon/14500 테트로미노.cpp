//난이도 : 골드5
//시작 : 17:11
//끝 :
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[502][502]; //점수 맵 
int visited[502][502]; //방문 표시
vector<int> result;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

//벽에 부딫히거나 방문했는지 판단
bool check(int r, int c) {
	if (r == N + 1 || r == 0 || c == M + 1 || c == 0) {
		return false;
	}
	else if (visited[r][c] == 1) {
		return false;
	}
	else {
		return true;
	}
}

void DFS(int r, int c, int cnt, int tmp_result) {
	if (cnt == 4) { //4개를 모두 방문하면 종료
		result.push_back(tmp_result); //결과 저장
		//cout << tmp_result << '\n';
		return;
	}
	visited[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int next_r = r + dir[i][0];
		int next_c = c + dir[i][1];
		if (check(next_r, next_c)) {
			visited[next_r][next_c] = 1; //방문 표시
			int tmp = tmp_result + map[next_r][next_c];
			DFS(next_r, next_c, cnt + 1, tmp); //DFS
			visited[next_r][next_c] = 0; //방문 해제
		}
	}
	visited[r][c] = 0; //처음 표시한 방문 표시 해제
	//이를 통해서 visited 배열을 모두 0으로 만든다.
}

//DFS로 불가능한 모양 4개 추가
int shape_1[3][2] = { {-1, 0}, {0, 1}, {1, 0} };
int shape_2[3][2] = { {0, 1}, {0, 2}, {1, 1} };
int shape_3[3][2] = { {0, 1}, {-1, 1}, {1, 1} };
int shape_4[3][2] = { {0, 1}, {-1, 1}, {0, 2} };

void special_1(int r, int c) {
	int tmp = map[r][c];
	int stop = false;
	for (int i = 0; i < 3; i++) {
		if (r + shape_1[i][0] >= N + 1 || r + shape_1[i][0] <= 0 || c + shape_1[i][1] >= M + 1 || c + shape_1[i][1] <= 0) {
			stop = true;
			break;
		}
		tmp += map[r + shape_1[i][0]][c + shape_1[i][1]];
	}
	if (!stop) {
		result.push_back(tmp);
	}
}
void special_2(int r, int c) {
	int tmp = map[r][c];
	int stop = false;
	for (int i = 0; i < 3; i++) {
		if (r + shape_2[i][0] >= N + 1 || r + shape_2[i][0] <= 0 || c + shape_2[i][1] >= M + 1 || c + shape_2[i][1] <= 0) {
			stop = true;
			break;
		}
		tmp += map[r + shape_2[i][0]][c + shape_2[i][1]];
	}
	if (!stop) {
		result.push_back(tmp);
	}
}
void special_3(int r, int c) {
	int tmp = map[r][c];
	int stop = false;
	for (int i = 0; i < 3; i++) {
		if (r + shape_3[i][0] >= N + 1 || r + shape_3[i][0] <= 0 || c + shape_3[i][1] >= M + 1 || c + shape_3[i][1] <= 0) {
			stop = true;
			break;
		}
		tmp += map[r + shape_3[i][0]][c + shape_3[i][1]];
	}
	if (!stop) {
		result.push_back(tmp);
	}
}
void special_4(int r, int c) {
	int tmp = map[r][c];
	int stop = false;
	for (int i = 0; i < 3; i++) {
		if (r + shape_4[i][0] >= N + 1 || r + shape_4[i][0] <= 0 || c + shape_4[i][1] >= M + 1 || c + shape_4[i][1] <= 0) {
			stop = true;
			break;
		}
		tmp += map[r + shape_4[i][0]][c + shape_4[i][1]];
	}
	if (!stop) {
		//cout << tmp << '\n';
		result.push_back(tmp);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];
		}
	}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
		/*	if (r == 5 && c == 9) {
				cout << "here" << '\n';
			}*/
			DFS(r, c, 1, map[r][c]);
			//for (int i = 1; i <= N; i++) {
			//	for (int j = 1; j <= M; j++) {
			//		cout << visited[i][j] << " ";
			//	}
			//	cout << '\n';
			//}
			//return 0;
			special_1(r, c);
			special_2(r, c);
			special_3(r, c);
			special_4(r, c);
		}
	}

	//결과 벡터 중 최대 값 출력
	int maxn = result[0];
	for (int i = 1; i < result.size(); i++) {
		if (maxn < result[i]) {
			maxn = result[i];
		}
	}

	cout << maxn << '\n';

	return 0;
}