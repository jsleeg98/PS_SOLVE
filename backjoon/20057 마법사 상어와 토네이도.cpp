//난이도 : 골드3
//시작 : 12:40
//끝 : 14:40
#include <iostream>
#include <vector>

using namespace std;

struct rate {
	int dr;
	int dc;
	float r;
};

int map[500][500];
vector<rate> t[4];
int N;
int sand_out = 0;
int dir_r[4] = { 0, 1, 0, -1 };
int dir_c[4] = { -1, 0, 1, 0 };

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << map[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void init() {
	//왼쪽 방향으로 음직일때의 각 위치와 퍼센트
	rate tmp[9];
	tmp[0].dc = 0;
	tmp[0].dr = -1;
	tmp[0].r = 0.01;

	tmp[1].dr = 1;
	tmp[1].dc = 0;
	tmp[1].r = 0.01;

	tmp[2].dr = -2;
	tmp[2].dc = -1;
	tmp[2].r = 0.02;

	tmp[3].dr = -1;
	tmp[3].dc = -1;
	tmp[3].r = 0.07;

	tmp[4].dr = 1;
	tmp[4].dc = -1;
	tmp[4].r = 0.07;

	tmp[5].dr = 2;
	tmp[5].dc = -1;
	tmp[5].r = 0.02;

	tmp[6].dr = -1;
	tmp[6].dc = -2;
	tmp[6].r = 0.1;

	tmp[7].dr = 1;
	tmp[7].dc = -2;
	tmp[7].r = 0.1;

	tmp[8].dr = 0;
	tmp[8].dc = -3;
	tmp[8].r = 0.05;

	for (int i = 0; i < 4; i++) {
		//벡터에 추가
		for (int j = 0; j < 9; j++) {
			t[i].push_back(tmp[j]);
		}
		//90도 회전
		for (int j = 0; j < 9; j++) {
			//이때 dr의 값을 저장하고 바꿔주고 나중에 저장한 dr을 dc에 대입해야한다.
			//r' = -c
			//c' = r
			//일 때 90도 회전된다.
			int tmp_dr = tmp[j].dr;
			tmp[j].dr = tmp[j].dc * (-1);
			tmp[j].dc = tmp_dr;
		}
	}

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < t[i].size(); j++) {
	//		cout << t[i][j].dr << " " << t[i][j].dc << " ";
	//		cout << t[i][j].r << '\n';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	
}

//현재 x위치 좌료, y위치 좌표, 방향정보를 받아 모래 흩뿌리기
void tonado(int xr, int xc, int yr, int yc, int dir) {
	int sand_y = map[yr][yc]; //y위치 모래양
	int spread_sand = 0; //날아간 모래양
	for (int i = 0; i < 9; i++) {
		int nr = xr + t[dir][i].dr; //비율계산하여 더해줄 위치 r
		int nc = xc + t[dir][i].dc; //비율계산하여 더해줄 위치 c
		int sand = sand_y * t[dir][i].r; //날아간 모래 양
		spread_sand += sand; //날아간 모래 양 누적
		if (nr >= N || nr < 0 || nc >= N || nc < 0) { //지도 밖으로 나간 경우
			sand_out += sand; //날아간 모래 처리
			continue;
		}
		//지도 내부인 경우
		map[nr][nc] += sand; // 날아간 모래 누적
	}
	int ar = yr + dir_r[dir]; //알파의 위치
	int ac = yc + dir_c[dir];
	//알파 위치가 지도 밖인 경우
	if (ar >= N || ar < 0 || ac >= N || ac < 0) {
		sand_out += sand_y - spread_sand;
	}
	else { //알파 위치가 지도 내인 경우
		map[ar][ac] += sand_y - spread_sand;
	}
	map[yr][yc] = 0; //y위치 모래 0으로 갱신
}

void move_tonado(int cr, int cc) {
	int xr = cr;
	int xc = cc;
	int dir_num = 0;
	//거리 1 수동 처리

	int distance = 1;
	while (1) {
		for (int j = 0; j < 2; j++) { //각 방향별 2번씩 반복
			int yr;
			int yc;
			for (int i = 0; i < distance; i++) { //한 방향마다 distance만큼 움직임
				yr = xr + dir_r[dir_num];
				yc = xc + dir_c[dir_num];
				tonado(xr, xc, yr, yc, dir_num); //토네이토 수행
				//print();
				xr = yr;
				xc = yc;
			}
			
			dir_num = (dir_num + 1) % 4;//방향 순환
		}
		distance++; //거리 추가
		if (distance == N) { 
			break;
		}
	}
	//마지막 라인 음직임
	for (int i = 0; i < distance - 1; i++) {
		int yr = xr + dir_r[dir_num];
		int yc = xc + dir_c[dir_num];
		tonado(xr, xc, yr, yc, dir_num);
		//print();
		xr = yr;
		xc = yc;
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}

	init();
	int center = N / 2;
	move_tonado(center, center);

	cout << sand_out << '\n';


	return 0;
}