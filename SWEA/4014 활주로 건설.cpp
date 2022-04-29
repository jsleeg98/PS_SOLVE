//시작 : 20:20
//끝 :
#include<iostream>

using namespace std;

int N, X;
pair<int, bool> map[20][20]; //높이, 다리를 세운 여부

//입력
void input() {
	cin >> N >> X;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int tmp;
			cin >> tmp;
			map[r][c].first = tmp;
			map[r][c].second = false; //다리를 안세운 것으로 초기화
		}
	}
}


int solve() {
	int cnt = 0;
	for (int r = 0; r < N; r++) { //행 기준으로 처리
		bool flag = true; //flag는 현재 행이 가능한지 여부 확인 
		for (int i = 0; i < N - 1; i++) {
			int a = map[r][i].first;
			int b = map[r][i + 1].first;
			if (b - a == -1) { //땅이 1 낮아지는 경우
				map[r][i + 1].second = true; //다리 지음 표시
				for (int j = 1; j < X; j++) { //뒤로 다리 길이만큼 확인
					i++;
					if (i + 1 >= N) { //범위 넘어가면 실패
						flag = false;
						break;
					}
					if (map[r][i+1].first != b) { //땅의 높이가 다리를 짓는 동안 달라지면 실패
						flag = false;
						break;
					}
					map[r][i + 1].second = true; //다리 지음 표시
				}
			}
			else if (b - a == 1) { //땅이 1높아지는 경우
				map[r][i].second = true; //다리 지음 표시
				for (int j = 1; j < X; j++) { //이전으로 확인
					if (i - j < 0) { //범위 넘어가면 실패
						flag = false;
						break;
					}
					if (a != map[r][i - j].first) { // 다리를 짓는 동안 높이가 달라지면 실패
						flag = false;
						break;
					}
					if (map[r][i - j].second == true) { //다리를 이미 지었으면 실패
						flag = false;
						break;
					}
					map[r][i - j].second = true; //다리 지음 표시
				}
			}
			else if(abs(b-a) > 1) { //땅의 높이가 1보다 크게 차이나면 실패
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	//열 기준으로 확인하기 위해 다리 지음 표시를 false로 초기화
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			map[r][c].second = false;
		}
	}

	//행 기준에서 열기준으로 바꿔서 실시
	for (int c = 0; c < N; c++) {
		bool flag = true;
		for (int i = 0; i < N-1; i++) {
			int a = map[i][c].first;
			int b = map[i+1][c].first;
			if (b-a == -1) {
				map[i + 1][c].second = true;
				for (int j = 1; j < X; j++) {
					i++;
					if (i + 1 >= N) {
						flag = false;
						break;
					}
					if (map[i + 1][c].first != b) {
						flag = false;
					}
					map[i + 1][c].second = true;
				}
			}
			else if (b - a == 1) {
				map[i][c].second = true;
				for (int j = 1; j < X; j++) {
					if (i - j < 0) {
						flag = false;
						break;
					}
					if (a != map[i - j][c].first) {
						flag = false;
						break;
					}
					if (map[i - j][c].second == true) {
						flag = false;
						break;
					}
					map[i - j][c].second = true;
				}
			}
			else if(abs(b-a) > 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	return cnt;
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
		input();
		int result;
		result = solve();
		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}