//난이도 : 골드5
//시작 : 11:32 - 11:49, 12:59 - 
//끝 : 14:50
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

//r, c 위치에서 부터 치킨 집 까지의 최단 거리
//BFS로 구하면 시간초과가 나온다!!!!
int BFS(int r, int c) {
	int result = 0;
	int visited[52][52] = { 0 };
	int distance[52][52] = { 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(r, c)); //현재 위치 큐에 push
	
	bool stop = false; //치킨 집 찾아서 멈추는 flag
	visited[r][c] = 1; //현 위치 방문 표시
	while (!q.empty()) {
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		int cur_distance = distance[cur_r][cur_c];
		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dir[i][0];
			int next_c = cur_c + dir[i][1];
			if (next_r > 0 && next_r < N + 1 && next_c > 0 && next_c < N + 1) { //벽에 부딫히지 않은 경우
				if (visited[next_r][next_c] == 0) { //방문하지 않은 경우
					visited[next_r][next_c] = 1; //방문 처리
					distance[next_r][next_c] = cur_distance + 1;
					if (tmp[next_r][next_c] == 2) { //가장 가까운 치킨집을 찾은 경우
						result = cur_distance + 1;
						//cout << result << '\n';
						stop = true;
					}
					q.push(make_pair(next_r, next_c)); //쿠에 삽입
				}
			}
		}
		if (stop) {
			break;
		}
	}
	return result;
}

//치킨집에 3개이므로 단순 좌표 거리 값으로 최단 거리 구하기
int chicken_distance(int r, int c, vector<pair<int, int>> v) {
	int result = 987654321;
	for (int i = 0; i < v.size(); i++) {
		int tmp = 0;
		tmp += abs(r - v[i].first);
		tmp += abs(c - v[i].second);
		if (result > tmp) { //최단 거리 저장
			result = tmp;
		}
	}
	return result;
}

//치킨 집의 위치 표시
vector<pair<int, int>> make_new_map(vector<pair<int, int>> v) {
	vector<pair<int, int>> house;
	//tmp에 map 복사하기
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c] == 2) { //원래 치킨집 자리 0으로 저장
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
		tmp[v[i].first][v[i].second] = 2; //치킨집 위치 표시
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

		vector<pair<int, int>> house; //집의 위치
		int tmp_result = 0;
		house = make_new_map(v); //집의 위치
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

		//집의 위치별 치킨 거리 모두 구하기
		for (int i = 0; i < house.size(); i++) {
			int r = house[i].first;
			int c = house[i].second;
			tmp_result += chicken_distance(r, c, v);
		}
		if (min_result > tmp_result) { //도시 치킨 거리 최소 값만 저장
			min_result = tmp_result;
		}

	}
	for (int i = idx; i < chicken.size(); i++) { //모든 치킨집 경우의 수 구하기
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

	//최소 도시 치킨 거리 출력
	cout << min_result << '\n';


	return 0;
}