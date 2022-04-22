//난이도 : 골드5
//시작 : 16:07
//끝 : 
#include <iostream>

using namespace std;
int N, M;
int map[50][50];
bool cloud[50][50];


int dir[9][2] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };



void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << map[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_cloud() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == true) {
				cout << r << " " << c << '\n';
			}
		}
	}
	cout << '\n';
}

//물 복사 함수
void copy_water(int r, int c) {
	int x_dir[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
	int cnt = 0; //물이 있는 곳의 수
	for (int i = 0; i < 4; i++) {
		int nr = r + x_dir[i][0];
		int nc = c + x_dir[i][1];
		//경계를 지나지 않는 경우
		if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
			if (map[nr][nc] > 0) { //물이 있다면
				cnt++;
			}
		}
	}
	map[r][c] += cnt;
}

void move_cloud(int d, int s) {
	bool tmp_cloud[50][50] = {0};
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << tmp_cloud[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';

	//구름 이동
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == true) {
				int nr = ((r + s * dir[d][0]) + (N * 30)) % N;
				int nc = ((c + s * dir[d][1]) + (N * 30)) % N;
				tmp_cloud[nr][nc] = true; //구름 이동 저장
				map[nr][nc] += 1; //물 양 1 증가
			}
		}
	}
	//임시 구름 위치 복사
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cloud[r][c] = tmp_cloud[r][c];
		}
	}

	//물 복사
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == true) {
				copy_water(r, c);
			}
		}
	}
	
	
	

}

//구름 생성 함수
void make_cloud() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (cloud[r][c] == false) { //구름이 있지 않던 곳
				if (map[r][c] >= 2) { //물의 양이 2 이상인 곳에서만
					map[r][c] -= 2; //물이 양이 2 감소
					cloud[r][c] = true; //구름 생성
				}
				else { //구름 없음
					cloud[r][c] = false;
				}
				
			}
			else { //그렇지 않으면 구름 생성 안됨
				cloud[r][c] = false;
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
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}

	cloud[N - 1][0] = true;
	cloud[N - 1][1] = true;
	cloud[N - 2][0] = true;
	cloud[N - 2][1] = true;

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		move_cloud(d, s);
		make_cloud();
		//print();
		//print_cloud();
	}

	//물의 양 세기
	int result = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			result += map[r][c];
		}
	}
	
	cout << result << '\n';


	return 0;
}