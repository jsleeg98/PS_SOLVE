//난이도 : 골드2
//시작 : 19:26
//끝 : 20:41
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
	v.clear(); //블록그룹 벡터 초기화
	
	queue<pair<int, int>> q;
	bool visited[21][21] = { 0 };

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int m;
			int size = 0;
			int rainbow = 0; //무지개 블록 개수
			vector<pair<int, int>> rainbow_v;
			block tmp;
			if (map[r][c] >= 1 && map[r][c] <= M && visited[r][c] == false) { //일반 블록이고 방문하지 않은 경우
				m = map[r][c]; //블록 번호 저장
				q.push({ r, c }); //큐에 push
				visited[r][c] = true; //방문 처리
				size++; //사이즈 +1
				tmp.blocks.push_back({ r, c }); //block 그룹에 속한 블록의 위치 추가
				while (!q.empty()) { //큐가 빌때까지
					int cr = q.front().first;
					int cc = q.front().second;
					q.pop(); //큐에서 pop
					for (int i = 0; i < 4; i++) {
						int nr = cr + dr[i];
						int nc = cc + dc[i];
						if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //범위를 넘어가면 패스
						if (map[nr][nc] == m || map[nr][nc] == 0){ //같은 블록이거나 무지개 블록일때만
							if (visited[nr][nc] == false) { //방문하지 않은 경우만 수행
								tmp.blocks.push_back({ nr, nc }); //block 그룹에 속한 블록의 위치 추가
								q.push({ nr, nc }); //큐에 push
								visited[nr][nc] = true; //방문 처리
								size++; //사이즈 +1
								if (map[nr][nc] == 0) { //무지개블록인 경우
									rainbow++; //무지개 블록 +1
									//visited[nr][nc] = false; //무지개 블록은 다른 블록이 방문할 수 있기 때문에 다시 미방문 처리해야함
									rainbow_v.push_back({ nr, nc });
								}
							}
						}
					}
				}
				//한 블록 그룹에서 사용한 무지개 블록은 다시 미방문 처리를 하여
				//다른 블록 그룹 생성 시 사용할 수 있도록 한다.
				for (int i = 0; i < rainbow_v.size(); i++) {
					visited[rainbow_v[i].first][rainbow_v[i].second] = false;
				}
				if (size > 1) { // 블록 개수가 2개 이상일 때만
					tmp.r = r;
					tmp.c = c;
					tmp.size = size;
					tmp.rainbow = rainbow;
					v.push_back(tmp); // 블록 그룹 추가
				}
			}
		}
	}
}

//점수 계산 함수
bool score() {
	bool stop = false;
	if (v.size() == 0) { //블록 그룹이 없는 경우
		stop = true; //멈춤
	}
	else {
		sort(v.begin(), v.end(), cmp_block); //정렬
		result += pow(v[0].size, 2);
		//cout << result << '\n';
		vector<pair<int, int>> pos_v = v[0].blocks;
		for (int i = 0; i < pos_v.size(); i++) {
			map[pos_v[i].first][pos_v[i].second] = -2; //없는 블록 처리
		}
	}
	return stop;
}

//블록 실제 내리는 함수
void down(int r, int c) {
	if (r + 1 == N + 1 || map[r+1][c] == -1) { //다음 블록이 검은색 블록이나 이미 맨 끝인 경우
		return; //멈춤
	}
	if (map[r + 1][c] == -2) { //빈칸인 경우에만 내리기가능
		map[r + 1][c] = map[r][c]; //블록 1칸 내리기
		map[r][c] = -2; //빈칸 처리
		down(r + 1, c);//재귀적 수행
	}
	
}

//중력 함수
void gravity() {
	for (int r = N; r >= 1; r--) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c] == -1) continue; //검은색 블록은 패스
			down(r, c);
		}
	}
}

//반시계 회전 함수
void rotate() {
	int tmp_map[21][21] = { 0 };
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int nr = N + 1 - c;
			int nc = r;
			tmp_map[nr][nc] = map[r][c]; //돌려서 임시 맵에 저장
		}
	}
	
	//map에 옮기기
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