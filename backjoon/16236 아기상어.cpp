//난이도 : 골드3
//시작 : 20:55
//끝 : 21:32
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//상어 구조체
struct shark {
	int r;
	int c;
	int eat;
	int size;
};

//물고기 구조체
struct fish {
	int r;
	int c;
	int distance;
};

int map[21][21]; //맵
vector<fish> v_fish; //먹을 수 있는 물고기 벡터
int N;
shark Shark;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int Time; //시간

void find_fish() {
	v_fish.clear(); //먹을 수 있는 물고기 벡터 초기화

	queue<pair<int, int>> q;
	int dist[21][21] = { 0 }; //거리 맵
	bool visited[21][21] = { 0 }; //방문 맵

	int r = Shark.r; //상어 위치
	int c = Shark.c; //상어 위치
	visited[r][c] = true; // 현위치 방문 처리
	q.push({ r, c }); //큐에 넣기
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		int distance = dist[cr][cc]; //현재 거리
		q.pop(); //큐 pop
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //맵 넘어가는 경우
			if (map[nr][nc] <= Shark.size) { //지나갈 수 있는 경우
				if (visited[nr][nc] == false) { //방문하지 않은 경우
					dist[nr][nc] = distance + 1; //거리 갱신
					visited[nr][nc] = true; //방문 처리
					q.push({ nr, nc }); //큐에 push
					if (map[nr][nc] < Shark.size && map[nr][nc] > 0) { //먹을 수 있는 물고기 추가
						fish tmp;
						tmp.r = nr;
						tmp.c = nc;
						tmp.distance = distance + 1;
						v_fish.push_back(tmp); //먹을 수 있는 물고기 추가
					}
				}
			}
		}
	}
	
}

//거리 작, r 작, c 작 우선 순위
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
	if (v_fish.size() == 0) { //먹을 수 있는 물고기가 없는 경우
		stop = true; //멈춤
	}
	else {
		sort(v_fish.begin(), v_fish.end(), cmp_fish); //물고기 정렬
		int fr = v_fish[0].r;
		int fc = v_fish[0].c;
		int distance = v_fish[0].distance; //먹을 수 있는 물고기 까지 거리
		Time += distance; //거리 만큼 시간 걸림 1초에 한칸
		map[Shark.r][Shark.c] = 0;//원래 있던곳 빈칸 처리
		Shark.r = fr; //상어 위치 갱신
		Shark.c = fc; //상어 위치 갱신
		Shark.eat += 1; //상어 먹은 물고기수 갱신
		map[fr][fc] = 9; //상어 위치 변경
		if (Shark.eat == Shark.size) { //먹은 물고기 수가 크기와 같다면
			Shark.size += 1; //크기 +1
			Shark.eat = 0; //먹은 물고기 수 갱신
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