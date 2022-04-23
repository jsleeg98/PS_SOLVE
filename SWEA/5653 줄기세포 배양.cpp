//시작 시간 : 20:00
//끝 시간 : 
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define SIZE 175

using namespace std;

struct cell {
	int r; //행 위치
	int c; //열 위치
	int life; //생명력
	int born_time; //생성된 시간
	int active_time; //활성화 시간
	int die_time; //죽는 시간
	bool state; //상태
};

int map[400][400]; //맵
vector<cell> v; //세포 정보 벡터
int N, M; //행 열
int K; //실행 시간
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void Print()
{
	for (int i = 140; i < 160; i++) {
		for (int j = 140; j < 160; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}


void init() {
	memset(map, 0, sizeof(map));
	v.clear();
}

void input() {
	cin >> N >> M >> K;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			int lif;
			cin >> lif;
			if (lif == 0) continue;//생명력 0이며 패스
			map[r + SIZE][c + SIZE] = lif; //맵에 생명력 표시
			
			cell tmp;
			tmp.r = SIZE + r;
			tmp.c = SIZE + c;
			tmp.life = lif;
			tmp.born_time = 0;
			tmp.active_time = tmp.born_time + tmp.life;
			tmp.die_time = tmp.born_time + tmp.life * 2;
			tmp.state = true;
			v.push_back(tmp);
		}
	}
}

void do_die(int Time) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].die_time == Time) {
			v[i].state = false;
		}
	}
}

bool compare(cell a, cell b) {
	return a.life > b.life;
}

void do_active(int Time) {
	vector<cell> tmp_v;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].state == false) continue;
		if (v[i].active_time == Time) {
			int r = v[i].r;
			int c = v[i].c;
			for (int j = 0; j < 4; j++) {
				int nr = r + dir[j][0];
				int nc = c + dir[j][1];
				if (map[nr][nc] == 0) {
					cell tmp;
					tmp.r = nr;
					tmp.c = nc;
					tmp.life = v[i].life;
					tmp.born_time = Time + 1;
					tmp.active_time = tmp.born_time + tmp.life;
					tmp.die_time = tmp.born_time + tmp.life * 2;
					tmp.state = true;
					tmp_v.push_back(tmp);
				}
			}
		}
	}
	if (tmp_v.size() == 0) return;
	sort(tmp_v.begin(), tmp_v.end(), compare);
	//for (int i = 0; i < tmp_v.size(); i++) {
	//	cout << tmp_v[i].r << " " << tmp_v[i].c << '\n';
	//}
	//cout << '\n';
	for (int i = 0; i < tmp_v.size(); i++) {
		int r = tmp_v[i].r;
		int c = tmp_v[i].c;
		if (map[r][c] == 0) {
			map[r][c] = tmp_v[i].life;
			v.push_back(tmp_v[i]);
		}
	}
}

int result() {
	int no_count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].state == false) no_count++;
		if (v[i].die_time == K) no_count++;
		if (v[i].born_time == K + 1) no_count++;
	}
	
	int ans = v.size() - no_count;
	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		input();
		//cout << v.size() << '\n';
		int Time = 0;
		//Print();
		while (1) {
			//cout << v.size() << '\n';
			if (Time == K) break;
			do_die(Time);
			do_active(Time);
			Time++;
			//Print();

		}


		int total = result();
		cout << "#" << test_case << " " << total << '\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}