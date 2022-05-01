#include <iostream>
#include <vector>

using namespace std;

int N;
int map[20][20];
//대각선 이동
int dr[] = { 1, 1, -1, -1 }; 
int dc[] = { -1, 1, 1, -1 };
int final_result = 0;

void init() {
	final_result = 0; //최종 답 초기화
}

//입력
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}
}

//실제로 사각형을 그리면서 디저트를 먹을 수 있는지 확인하고 개수 세는 함수
void eat(int r , int c, int d1, int d2) {
	vector<int> food;
	food.push_back(map[r][c]); //현 위지 디저트 추가
	int cr;
	int cc;
	int sr = r; //시작 위치 갱신
	int sc = c; //시작 위치 갱신
	for (int i = 1; i <= d1; i++) { //사각형 한변 그리기
		int nr = sr + dr[0] * i;
		int nc = sc + dc[0] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	sr = cr; //시작 위치 갱신
	sc = cc; //시작 위치 갱신

	for (int i = 1; i <= d2; i++) { //사각형 한변 그리기
		int nr = sr + dr[1] * i;
		int nc = sc + dc[1] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	sr = cr; //시작위치 갱신
	sc = cc; //시작위치 갱신

	for (int i = 1; i <= d1; i++) { //사각형 한변 그리기
		int nr = sr + dr[2] * i;
		int nc = sc + dc[2] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	sr = cr; //시작위치 갱신
	sc = cc; //시작위치 갱신

	for (int i = 1; i < d2; i++) { //사각형 한변 그리기 이때는 다시 돌아오는 위치는 빼기 위해 <를 사용
		int nr = sr + dr[3] * i;
		int nc = sc + dc[3] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	//디저트 종류가 겹치는지 확인
	bool stop = false;
	int num[101] = { 0 };
	for (int i = 0; i < food.size(); i++) {
		if (num[food[i]] == 1) { //겹치는 경우
			stop = true; //멈춤 표시
			break;//멈춤
		}
		num[food[i]]++;
	}

	//int result = 0;
	if (stop == false) { //종류가 겹치지 않는 경우
		int result = food.size();
		final_result = max(final_result, result); //최종 답 갱신
	}

	

}

//가능한 경우의 수 탐색
void solve() {
	for (int r = 0; r < N; r++) {
		for (int c = 1; c < N - 1; c++) {
			for (int d1 = 1; d1 <= N - 2; d1++) {
				if (c - d1 < 0) break; //d1이 너무 큰 경우 패스
				for (int d2 = 1; d2 < N - r - d1; d2++) {
					if (c + d2 >= N) break; //d2가 너무 큰 경우 패스
					if (r + d2 >= N) break; //d2가 너무 큰 경우 패스
					if (c - d1 + d2 >= N) continue; //패스 
					if (r + d1 + d2 >= N) continue; //패스
					//cout << r << " " << c << " " << d1 << " " << d2 << '\n';
					eat(r, c, d1, d2); //디저트 확인
					
					//cout << final_result << '\n';
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		input();
		solve();
		if (final_result != 0) { //디저트를 먹을 수 있는 경우
			cout << "#" << test_case << " " << final_result << '\n';
		}
		else { //디저트를 먹을 수 없는 경우
			cout << "#" << test_case << " " << -1 << '\n';
		}
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}