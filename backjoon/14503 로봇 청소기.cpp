//난이도 : 골드5
//시작 : 21:44
//끝 : 23:11
#include <iostream>

using namespace std;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };//북, 동, 남, 서
int map[50][50];
int N, M;

//왼쪽 보기
int change_dir(int dir_num) {
	dir_num -= 1;
	if (dir_num == -1) {
		dir_num = 3;
	}
	return dir_num;
}

//재귀적으로 구현하려고 했지만 불가능하다!!!!
int clean(int r, int c, int cnt, int dir_num, int result) {
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	cout << '\n';
	if (cnt == 4) { //네 방향을 다 본 경우
		int back_num = change_dir(dir_num);
		back_num = change_dir(back_num); //왼쪽으로 두번 돌면 후진 방향
		int back_r = r + dir[back_num][0];
		int back_c = c + dir[back_num][1];
		if (map[back_r][back_c] != 1) {
			cout << "back" << '\n';
			clean(back_r, back_c, 0, dir_num, result); //방향은 그대로 후진하여 한번의 기회를 더 준다.
			//최종 return을 하여도 이 부분으로 돌아와서 cnt == 4인 상태로 계속 진행되어 무한 반복된다.
			//따라서 재귀적으로 구현하면 해결 불가능!!!!!!!
		}
		else {
			//for (int i = 0; i < N; i++) {
			//	for (int j = 0; j < M; j++) {
			//		cout << map[i][j] << " ";
			//	}
			//	cout << '\n';
			//}
			return result;
		}
	}
	dir_num = change_dir(dir_num); //현재 방향에서 왼쪽 보기
	int next_r = r + dir[dir_num][0]; //왼쪽 방향 행
	int next_c = c + dir[dir_num][1]; //왼쪽 방향 열
	if (map[next_r][next_c] == 0) { //왼쪽 방향이 빈칸이라면
		map[next_r][next_c] = 2; //다음 위치 청소 처리
		clean(next_r, next_c, 0, dir_num, result+1); //청소기 움직이고 다음 청소 시작
	}
	else { //빈칸이 아닌 경우
		clean(r, c, cnt + 1, dir_num, result); //카운트 올린다.
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;
	int cur_r, cur_c;
	int dir_num;
	cin >> cur_r >> cur_c >> dir_num;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
		}
	}


	int result = 0;
	while (1) {
		if (map[cur_r][cur_c] == 0) {
			map[cur_r][cur_c] = 2; //청소 처리
			result++; //청소한 구역 +1
		}

		bool check_4 = true;
		for (int i = 0; i < 4; i++) {
			dir_num = (dir_num + 3) % 4; //왼쪽 방향
			int next_r = cur_r + dir[dir_num][0];
			int next_c = cur_c + dir[dir_num][1];
			if (map[next_r][next_c] == 0) { //빈칸이라면
				cur_r = next_r;
				cur_c = next_c;
				check_4 = false; //4 방향 중에 빈칸이 있는 경우 false로 표시
				break; //다음 위치로 이동
			}
		}

		//4방향 모두 빈칸이 아닌 경우
		if (check_4) {
			int back_dir = (dir_num + 2) % 4; // 후진 방향
			int back_r = cur_r + dir[back_dir][0];
			int back_c = cur_c + dir[back_dir][1];
			if (map[back_r][back_c] == 1) { //후진했는지 뒤가 벽인 경우
				break; // 종료
			}
			else { //벽이 아닌 경우 후진 이동
				cur_r = back_r;
				cur_c = back_c;
			}
		}
	}

	//청소한 구역 출력
	cout << result << '\n';

	return 0;
}