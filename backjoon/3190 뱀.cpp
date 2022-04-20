//난이도 : 골드5
//시작 : 10:05
//끝 :
#include <iostream>
#include <queue>

using namespace std;

int map[102][102] = {0}; // map 상하좌우 padding
int N; // 맵 크기
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char X[10001]; //방향이 바뀌는 시간 저장

bool stop(int r, int c) {
	//벽에 부딫힌 경우
	if (r == N + 1 || r == 0 || c == N + 1 || c == 0) {
		return false;
	}
	//몸에 부딫힌 경우
	else if (map[r][c] == 1) {
		return false;
	}
	//부딫히지 않은 경우
	else{
		return true;
	}

}

int dir_change(int dir, char C) {
	if (C == 'D') {
		dir += 1;
	}
	else if (C == 'L') {
		dir -= 1;
	}

	if (dir == -1) {
		dir = 3;
	}
	else if (dir == 4) {
		dir = 0;
	}

	return dir;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	//사과 위치 표시
	int apple;
	cin >> apple;
	int r, c;
	for (int i = 0; i < apple; i++) {
		
		cin >> r >> c;
		map[r][c] = 2;
	}

	int dir_num_cnt; //방향 전환 횟수
	cin >> dir_num_cnt;
	for (int i = 0; i < dir_num_cnt; i++) {
		int sec;
		char D;
		cin >> sec >> D;
		X[sec] = D;
	}

	queue<pair<int, int>> snake;
	snake.push(make_pair(1, 1)); //현재 뱀 위치 
	map[1][1] = 1; //현재 뱀 위치 맵 표시
	int dir_num = 0;

	int cnt = 0;
	while (true) {
		//cout << dir_num << '\n';
		//머리 현재 위치
		int head_r, head_c;
		head_r = snake.back().first;
		head_c = snake.back().second;
		//머리 움직이기
		head_r += dir[dir_num][0];
		head_c += dir[dir_num][1];
		snake.push(make_pair(head_r, head_c)); //머리 위치 push
		cnt++; //시간 늘리기
		//부딫혔는지 여부 확인
		if (!stop(head_r, head_c)) {
			break; //종료
		}
		
		if (map[head_r][head_c] == 0) { //사과가 없으면 pop
			map[head_r][head_c] = 1;
			map[snake.front().first][snake.front().second] = 0; //꼬리 지우기
			snake.pop(); //꼬리 pop
		}
		else if (map[head_r][head_c] == 2) { //사과가 있으면 그대로
			map[head_r][head_c] = 1;
		}
		
		if (X[cnt] == 'L') {
			dir_num = dir_change(dir_num, 'L');
		}
		else if (X[cnt] == 'D') {
			dir_num = dir_change(dir_num, 'D');
		}

	/*	for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				cout << map[r][c] << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
	}

	cout << cnt << '\n';

	return 0;
}