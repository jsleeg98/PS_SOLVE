//난이도 : 골드4
//시작 : 19:10
//끝 :
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
	//시계방향 90도 회전
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			tmp[j][l - 1 - i] = map[i + x][j + y];
		}
	}

	//맵 갱신
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
			int cnt = 0; // 주변 얼음 개수
			for (int i = 0; i < 4; i++) {
				int nr = r + dir[i][0];
				int nc = c + dir[i][1];
				if (nr >= 0 && nr < NN && nc >= 0 && nc < NN) {
					if (map[nr][nc] > 0) { //얼음인 경우
						cnt++; //주변 얼음 개수 ++
					}
				}
			}
			if (cnt < 3) { //주변 얼음 개수가 3 미만인 경우
				melt_map[r][c] = true; // 녹이기 맵 true
			}
		}
	}

	//녹이기 맵이 차이고 녹일 얼음이 있는 경우 얼음 녹이기
	for (int r = 0; r < NN; r++) {
		for (int c = 0; c < NN; c++) {
			if (melt_map[r][c] == true && map[r][c] > 0) {
				map[r][c] -= 1; //얼음 녹이기
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
			int cnt = 0; //덩어리 개수
			while (!q.empty()) {
				cnt++; //덩어리 개수 추가
				int cr = q.front().first;
				int cc = q.front().second;
				q.pop(); //pop
				//visited[cr][cc] = 1; //방문 표시
				for (int i = 0; i < 4; i++) { //4방향에 대하여 인접하는 얼음이 있는지 파익
					int nr = cr + dir[i][0];
					int nc = cc + dir[i][1];
					if (nr >= 0 && nr < NN && nc >= 0 && nc < NN) {//벽을 넘지 않는 경우
						if (visited[nr][nc] == 0) { //방문하지 않은 경우
							if (map[nr][nc] > 0) { //얼음인 경우
								q.push(make_pair(nr, nc)); //얼음 덩어리 큐에 추가
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
			if (maxn < cnt) { //최대 값만 저장
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
		//구역 나누기
		//맨위 맨 왼쪽을 대표로 저장 
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