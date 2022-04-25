//난이도 : 골드2
//시작 : 17:45 - 18:24
//끝 : 19:45 - 22:50
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
	int r;
	int c;
	int d;
	bool live;
	vector<int> prior[5];
};

//상어 번호 1번 부터
struct Map {
	vector<int> V;
	int smell_time;
	int smell_host;
};

Map map[20][20]; //맵 정보
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, -1, 1 };

int N, M, K;
int die_cnt = 0;
Shark shark[401];

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (map[r][c].V.size() != 0) {
				cout << map[r][c].V[0] << " ";
			}
			else {
				cout << "-" << " ";
			}
			
		}
		cout << '\n';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M >> K;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int shark_num;
			cin >> shark_num;
			map[r][c].smell_host = 0;
			map[r][c].smell_time = 0;
			if (shark_num != 0) {
				shark[shark_num].r = r;
				shark[shark_num].c = c;
			}
		}
	}

	for (int i = 1; i <= M ; i++) {
		int d;
		cin >> d;
		shark[i].d = d;
		shark[i].live = true;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				int d;
				cin >> d;
				shark[i].prior[j].push_back(d);
			}
		}
	}
}

//맵에 냄새 할당
void smell(int Time) {
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue; //죽으면 패스
		int r = shark[i].r;
		int c = shark[i].c;
		map[r][c].smell_host = i; //냄새 주인 할당
		map[r][c].smell_time = Time + K; //냄새가 없어지는 시간
	}
}

//상어 이동시키기
void move_shark(int Time) {
	//map 초기화
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue; //죽으면 패스
		map[shark[i].r][shark[i].c].V.clear(); //현재 상어 위치 지우기
	}


	//살아있는 상어의 다음 위치 찾기
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue;//죽으면 패스
		int cr = shark[i].r;
		int cc = shark[i].c;
		int d = shark[i].d;
		bool check = false;
		int xr = -1;
		int xc = -1;
		int xd = -1;
		for (int j = 0; j < 4; j++) { //우선순위 순으로 찾기
			int nd = shark[i].prior[d][j];
			int nr = cr + dr[nd];
			int nc = cc + dc[nd];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;//범위 벗어나면 패스
			if (map[nr][nc].smell_time <= Time) { //빈칸을 찾은 경우
				map[nr][nc].V.push_back(i); //맵에 상어 추가
				shark[i].r = nr;
				shark[i].c = nc;
				shark[i].d = nd;
				check = true; //체크 표시
				break; //멈춤
			}
			else if (map[nr][nc].smell_host == i) { //같은 냄새를 찾은 경우
				if (xr == -1) {
					xr = nr;
					xc = nc;
					xd = nd;
				}
			}

		}
		if (check == false) { //빈칸을 못찾은 경우
			//처음으로 찾은 같은 냄새 칸으로 이동
			shark[i].r = xr;
			shark[i].c = xc;
			shark[i].d = xd;
			map[xr][xc].V.push_back(i); //맵에 상어 추가
		}

	}
}

//상어 죽이기
void kill_shark() {
	for (int i = 1; i <= M; i++) {
		if (shark[i].live == false) continue; //죽으면 패스
		int r = shark[i].r;
		int c = shark[i].c;
		if (map[r][c].V.size() > 1) { //한 칸에 2마리 이상의 상어가 있는 경우
			sort(map[r][c].V.begin(), map[r][c].V.end()); //상어 번호로 오름차순 정렬
			for (int j = map[r][c].V.size() - 1; j > 0 ; j--) { //끝 상어부터 pop하면서 죽은 상어의 수 세기
				shark[map[r][c].V[j]].live = false; //죽임
				map[r][c].V.pop_back();//맵에서 제거
				die_cnt++; //죽인 상어의 수 +1
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int time = 0;
	bool normal = false;
	while (1) {
		
		if (time >= 1000) { //1000초가 넘으면 종료
			break;
		}
		smell(time);
		move_shark(time);
		kill_shark();
		if (M - die_cnt == 1) {
			normal = true;
			break;
		}
		time++;
		//print();
	}

	if (normal == true) {
		cout << time + 1 << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	return 0;
}