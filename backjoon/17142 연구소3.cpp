//난이도 : 골드4
//시작 : 21:56
//끝 :
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
	//tmp_map에 맵 복사
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			tmp_map[r][c] = map[r][c];
			check_map[r][c] = map[r][c];
		}
	}



	////현재 있는 모든 바이러스를 빈칸으로 만들기
	//for (int i = 0;i <  virus.size(); i++) {
	//	tmp_map[virus[i].first][virus[i].second] = 0;
	//}

	////선택한 바이러스 위치 2로 만들기
	//for (int i = 0; i < sel_virus.size(); i++) {
	//	tmp_map[sel_virus[i].first][sel_virus[i].second] = 2;
	//}

	//print();
	int visited[50][50] = { 0 };
	int distance[50][50] = { 0 };
	queue<pair<int, int>> q;

	//처음 위치 방문 처리
	for (int i = 0; i < sel_virus.size(); i++) {
		visited[sel_virus[i].first][sel_virus[i].second] = 1;
	}
	//큐에 시작 위치 넣기
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
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;//맵 넘어가면 패스
			if (visited[nr][nc] == 1) continue;

			if (tmp_map[nr][nc] == 0 || tmp_map[nr][nc] == 2) {
				distance[nr][nc] = dis + 1; //distance가 시간과 같은 의미
				visited[nr][nc] = 1; //방문 표시
				/*tmp_map[nr][nc] = dis + 1;*/
				if (tmp_map[nr][nc] == 0) { //새롭게 감염 시켰을 때만
					infect++; //감염 시킨 칸 추가
					time = distance[nr][nc]; //시간 갱신 //자동적으로 맨 마지막에는 최대 시간이 저장
				}
				q.push({ nr, nc }); //빈칸이거나 비활성 바이러스 이거나 큐에 추가
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
	

	
	//모두 감염을 못시킨 경우
	if (infect != blank) {
		time = 999999999; //시간 무한
	}

	result = min(result, time); //최소 시간만 결과에 저장

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

//모든 경우의 수 
void DFS(int virus_cnt, vector<pair<int, int>> sel_virus, int idx) {
	if (virus_cnt == M) { //M개를 모두 고른 경우 
		BFS(sel_virus);//감염 시켜서 확인
		return;
	}
	//활성 바이러스 경우의 수 파악
	for (int i = idx; i < virus.size(); i++) {
		sel_virus.push_back(virus[i]); //현재 인덱스를 활성 바이러스로 추가 
		DFS(virus_cnt + 1, sel_virus, i + 1); //다음 경우 확인
		sel_virus.pop_back(); //현재 인덱스를 활성 바이러스에서 제거 //다른 경우의 수를 위함
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