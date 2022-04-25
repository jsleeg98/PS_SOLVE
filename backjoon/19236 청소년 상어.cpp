//난이도 : 골드2
//시작 : 13:08
//끝 :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fish {
	int r;
	int c;
	int d;
	bool live;
};

int dr[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 }; //1부터 시작
int dc[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int map[4][4]; //물고기 번호 저장, 0 빈칸, -1 상어
int tmp_map[4][4]; //현재까지 맵 저장해놓기
Fish fish[17]; //물고기 정보 저장 배열 //인덱스가 번호
int score;

void print() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << map[r][c] << " ";// << map[r][c].d << " "; // << map[r][c].r << " " << map[r][c].c << " " << map[r][c].d << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void input() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			int n, d;
			cin >> n >> d;
			Fish tmp;
			tmp.r = r;
			tmp.c = c;
			tmp.d = d;
			tmp.live = true;
			fish[n] = tmp;
			map[r][c] = n;
		}
	}
}

//물고기 정보를 바꾸는 함수
void swap_fish(int a, int b) {
	int tmp_r = fish[a].r;
	int tmp_c = fish[a].c;
	fish[a].r = fish[b].r;
	fish[a].c = fish[b].c;
	fish[b].r = tmp_r;
	fish[b].c = tmp_c;
}

//물고기를 움직이는 함수
void move_fish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].live == false) continue; //죽으면 패스
		int cr = fish[i].r;
		int cc = fish[i].c;
		int d = fish[i].d;
		d--; //다음 루프에서 원래 자신의 방향부터 수행하기 위해 -1
		for (int j = 0; j < 8; j++) {
			d++; //방향 정보를 +1하면서 8방향 수행
			if (d >= 9) d = 1; //d가 9 이상이면 1로 순환
			int nr = cr + dr[d];
			int nc = cc + dc[d];
			if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue; //맵 넘어가면 패스
			if (map[nr][nc] == -1) continue; //상어가 있으면 패스
			if (map[nr][nc] == 0) { //빈칸인 경우
				map[nr][nc] = map[cr][cc]; //빈칸으로 이동
				map[cr][cc] = 0; //현재 칸 빈칸 처리
				//현재 물고기 정보 업데이트
				fish[i].r = nr;
				fish[i].c = nc;
				fish[i].d = d;
				break;
			}
			else if (map[nr][nc] >= 1 && map[nr][nc] <= 16) { //물고기가 있는 경우
				int tmp = map[cr][cc]; //원래 물고기 번호 임시 저장
				map[cr][cc] = map[nr][nc]; //맵 바꾸기
				map[nr][nc] = tmp; //맵 바꾸기
				swap_fish(map[cr][cc], map[nr][nc]); //물고기 정보 갱신
				fish[i].d = d; //방향 바꾸기
				break;
			}
		}
		//print();
	}
}

//나중에 맵을 되돌리기 위해 초기 맵 복사해놓는 함수
//배열은 포인터로 들어오기 때문에 얕은 복사가 된다.
void copy_map_fish(int map[][4], int copy_map[][4], Fish fish[], Fish copy_fish[]) {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			copy_map[r][c] = map[r][c];
		}
	}

	for (int i = 1; i <= 16; i++) {
		copy_fish[i] = fish[i];
	}
}

//eat이 true이면 물고기를 먹고
//eat이 false이면 물고기를 뱉는다.
void eat_fish(int sr, int sc, int nr, int nc, int fish_num, bool eat) {
	if (eat == true) {
		fish[fish_num].live = false;//물고기 죽음
		map[nr][nc] = -1; //맵에 상어 표시
		map[sr][sc] = 0; //원래 상어가 있던 자리 빈칸 처리
	}
	else {
		fish[fish_num].live = true;//물고기 살림
		map[nr][nc] = fish_num; //물고기 되돌림
		map[sr][sc] = -1; //상어 표시
	}
}

//상어 위치 r, 상어 위치 c, 상어 방향 d, 현재 점수 sum
void DFS(int sr, int sc, int sd, int sum) {
	//print();
	score = max(score, sum); //최대값만 score에 저장
	//cout << score << '\n';
	int prev_map[4][4];
	Fish prev_fish[17];
	copy_map_fish(map, prev_map, fish, prev_fish);
	//print();
	move_fish();
	//print();
	for (int i = 1; i <= 3; i++) {
		int nr = sr + dr[sd] * i;
		int nc = sc + dc[sd] * i;
		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break; //맵을 넘어간 경우 멈춤
		if (map[nr][nc] == 0) continue; //빈칸인 경우 패스
		
		int fish_num = map[nr][nc];
		int d = fish[fish_num].d;
		
			
		eat_fish(sr, sc, nr, nc, fish_num, true); //물고기 먹어보기
		DFS(nr, nc, d, sum + fish_num); //다음 경우의 수 수행 
		eat_fish(sr, sc, nr, nc, fish_num, false); //물고기 뱉기
			

		

	}
	copy_map_fish(prev_map, map, prev_fish, fish); //다른 경우의 수를 위해 맵 되돌려놓기

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	bool stop;
	input();

	//초기 상어의 위치와 score 초기화
	int sr = 0;
	int sc = 0;
	int fish_num = map[sr][sc];
	int d = fish[fish_num].d;
	fish[fish_num].live = false;
	map[sr][sc] = -1; //상어 표시
	score += fish_num; // 점수 추가

	DFS(sr, sc, d, score);

	cout << score << '\n';

	return 0;
}