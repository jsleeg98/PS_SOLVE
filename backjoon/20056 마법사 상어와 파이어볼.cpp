//난이도 : 골드4
//시작 : 21:54 - 22:14
//끝 : 14:00 - 16:30
#include <iostream>
#include <queue>

using namespace std;

struct FB {
	int r;
	int c;
	int m;
	int s;
	int d;
};

int N; //맵 가로 세로 크기
int M; //초기 파이어볼 개수
int K; //이동 명령 횟수


int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
vector<FB> map[51][51];
vector<FB> tmp_map[51][51];
vector<FB> fireball;

int sum_mass() {
	int total = 0;
	for (int i = 0; i < fireball.size(); i++) {
		total += fireball[i].m;
	}
	return total;
}

//파이어볼을 합치는 함수
void check_fb() {
	
	fireball.clear(); // fireball 비우기

	//map에 있는 파이어볼의 개수를 기준으로 파이어볼을 처리하여
	//fireball 벡터에 삽입
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c].size() == 0) continue;
			else if (map[r][c].size() == 1) {
				tmp_map[r][c].push_back(map[r][c][0]); //임시 맵에 추가
				fireball.push_back(map[r][c][0]); //fireball 추가
			}
			else {
				int m = 0;
				int s = 0; 
				int d = 0;
				int cnt = map[r][c].size();
				bool even = false;
				bool odd = false;
				for (int i = 0; i < map[r][c].size(); i++) {
					m += map[r][c][i].m;
					s += map[r][c][i].s;
					if (map[r][c][i].d % 2 == 0) {
						even = true;
					}
					else {
						odd = true;
					}
				}
				m /= 5; //질량 갱신
				s /= cnt; //속도 갱신
				if (m > 0) {
					if (even && odd) {//짝홀 섞인 경우
						for (int i = 1; i < 8; i += 2) {
							FB tmp;
							tmp.r = r;
							tmp.c = c;
							tmp.m = m;
							tmp.s = s;
							tmp.d = i;
							fireball.push_back(tmp);
						}
					}
					else {
						for (int i = 0; i < 8; i += 2) {
							FB tmp;
							tmp.r = r;
							tmp.c = c;
							tmp.m = m;
							tmp.s = s;
							tmp.d = i;
							fireball.push_back(tmp);
						}
					}
				}
			}
		}
	}
}

//파이어 볼 이동 함수
void move() {

	//맵 초기화
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			map[r][c].clear();
		}
	}

	//파이어볼의 현재 위치를 가지고 움직여서 map에 할당
	for (int i = 0; i < fireball.size(); i++) {
		int r = fireball[i].r;
		int c = fireball[i].c;
		int s = fireball[i].s;
		int d = fireball[i].d;
		int nr = r + (s % N) * dir[d][0];
		int nc = c + (s % N) * dir[d][1];
		if (nr < 1) nr += N;
		if (nr > N) nr -= N;
		if (nc < 1) nc += N;
		if (nc > N) nc -= N;

		fireball[i].r = nr;
		fireball[i].c = nc;
		map[nr][nc].push_back(fireball[i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	
	for (int i = 0; i < M; i++) {
		FB tmp;
		cin >> tmp.r >> tmp.c >> tmp.m >> tmp.s >> tmp.d;
		map[tmp.r][tmp.c].push_back(tmp);
		fireball.push_back(tmp);
	}


	while (K > 0) {
		K--;
		move();
		check_fb();
	}

	int result = sum_mass();
	cout << result << '\n';

	return 0;
}