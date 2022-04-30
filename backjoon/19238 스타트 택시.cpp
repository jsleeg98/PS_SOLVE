#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//택시 자료형
struct TAXI {
	int r;
	int c;
	int gas;
};

//사용자 위치
struct user_pos {
	int r;
	int c;
	int dst_r;
	int dst_c;
};

//위치 자료형
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

//입력
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

//거리, 행, 열 우선순위 오름차순 정렬
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
	v.clear(); //태울 수 있는 사용자 벡터 초기화
	bool visited[21][21] = { 0 };
	int distance[21][21] = { 0 };
	queue<pos> q;
	q.push({ taxi.r, taxi.c });
	visited[taxi.r][taxi.c] = true;

	if (user_map[taxi.r][taxi.c].size() > 0) { //현재 위치에서 바로 태울 수 있는 승객이 있는 경우
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
			if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //범위를 넘으면 패스
			if (map[nr][nc] == 1) continue; //벽은 패스
			if (visited[nr][nc] == false) { //방문하지 않은 경우
				visited[nr][nc] = true;
				distance[nr][nc] = dist + 1;
				q.push({ nr, nc });
				if (user_map[nr][nc].size() > 0) {
					v.push_back({ user_map[nr][nc][0], dist + 1 }); //태울 수 있는 승객이 있는 경우
				}
			}
		}
	}

}

//도착지 까지의 거리
int BFS_2(int dst_r, int dst_c) {
	int dst_distance = 0; //도착지까지 거리
	bool visited[21][21] = { 0 };
	int distance[21][21] = { 0 };
	queue<pos> q;
	q.push({ taxi.r, taxi.c });
	visited[taxi.r][taxi.c] = true; //현 위치 방문 처리
	while (!q.empty()) {
		int cr = q.front().r;
		int cc = q.front().c;
		int dist = distance[cr][cc];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 1 || nr > N || nc < 1 || nc > N) continue; //범위 넘으면 패스
			if (map[nr][nc] == 1) continue; //벽은 패스
			if (visited[nr][nc] == false) { //방문하지 않은 경우 
				visited[nr][nc] = true;
				distance[nr][nc] = dist + 1;
				q.push({ nr, nc });
				if (nr == dst_r && nc == dst_c) { //도착지에 도착한 경우
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
	if (v.size() == 0) { //태울 수 있는 손님이 없는 경우
		return true;
	}


	sort(v.begin(), v.end(), cmp_pair); //정렬

	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i].first.r << " " << v[i].first.c << " " << v[i].second << '\n';
	//}
	//cout << '\n';

	int distance = v[0].second;
	int user_r = v[0].first.r;
	int user_c = v[0].first.c;
	int dst_r = v[0].first.dst_r;
	int dst_c = v[0].first.dst_c;

	if (taxi.gas >= distance) { //사용자가 있는 곳까지 갈 수 있는 경우
		taxi.r = user_r;
		taxi.c = user_c;
		taxi.gas -= distance;
		user_map[user_r][user_c].pop_back(); //손님 태워 없애기
	}
	else { //갈 수 없는 경우
		stop = true;
	}

	int dst_distance = BFS_2(dst_r, dst_c);

	if (dst_distance == 0) { //도착지에 갈 수 없는 경우
		return true;
	}

	if (taxi.gas >= dst_distance) { //도착지에 갈 수 있는 경우
		taxi.r = dst_r;
		taxi.c = dst_c;
		taxi.gas -= dst_distance;
		taxi.gas += dst_distance * 2;
	}
	else { //갈수 없는 경우
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

	if (stop) { //중도에 끝난 경우
		cout << -1 << '\n';
	}
	else { //손님들을 다 태워준 경우
		cout << taxi.gas << '\n';
	}



	return 0;
}