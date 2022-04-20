//난이도 : 골드5
//시작 : 19:30
//끝 : 21:43
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[8][8];
int tmp[8][8];
int N, M;
int result = 0; //최대 값 저장

//바이러스를 퍼트린 뒤 빈칸을 찾는 함수
void virus_BFS() {
	int final_map[8][8];
	queue<pair<int, int>> virus;
	//최종 맵 복사
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			final_map[r][c] = tmp[r][c];
			if (final_map[r][c] == 2) { //바이러스 위치 큐에 push
				virus.push(make_pair(r, c));
			}
		}
	}

	//오른쪽, 아래, 왼쪽, 위
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	//BFS를 이용하여 바이러스 퍼트리기
	while (!virus.empty()) {
		int r = virus.front().first;
		int c = virus.front().second;
		virus.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_r = r + dir[i][0];
			int next_c = c + dir[i][1];
			if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) { //벽에 부딫히지 않은 경우
				if (final_map[next_r][next_c] == 0) { //빈칸인 경우에만 push
					final_map[next_r][next_c] = 2; //바이러스 표시
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
	//빈칸 개수 세기
	int empty = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (final_map[r][c] == 0) {
				empty++;
			}
		}
	}

	//최대 빈칸의 개수로 result 업데이트
	result = max(result, empty);
}

//벽을 쌓는 함수로 cnt는 현재까지 세운 벽의 수를 의미한다.
void make_wall(int cnt) {
	if (cnt == 3) { //벽 3개를 세운 경우
		virus_BFS(); //바이러스 퍼트리고 빈칸 세기
		
		return;
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (tmp[r][c] == 0) {
				tmp[r][c] = 1; //벽 세우기
				make_wall(cnt + 1); //다음 벽 세우기
				tmp[r][c] = 0; //벽 없애기
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
			if (map[r][c] == 0) { //빈칸을 찾으면
				//map을 tmp에 복사
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						tmp[i][j] = map[i][j];
					}
				}

				tmp[r][c] = 1; //벽 세우기
				make_wall(1);  //다음 벽 세우기
				tmp[r][c] = 0; //벽 없애기
				
			}
		}
	}

	//최대 빈칸 수 출력
	cout << result << '\n';

	return 0;
}