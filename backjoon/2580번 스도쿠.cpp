//난이도 : 골드4
//시작 : 10:40 - 11:48
//끝 :
#include <iostream>
#include <vector>
 
using namespace std;

int puzzle[9][9] = { 0 }; //스도쿠 퍼즐 저장 배열
vector<pair<int, int>> blank; //빈 칸 위치 저장 벡터
bool stop = false; //끝남 표시

//pruning 조건
bool is_available(int cur_r, int cur_c) {
	for (int r = 0; r < 9; r++) { //같은 행에 같은 숫자가 있으면 탈락, 자기 자신은 패스
		if (puzzle[cur_r][cur_c] == puzzle[r][cur_c] && cur_r != r) {
			return false;
		}
	}
	for (int c = 0; c < 9; c++) { //같은 열에 같은 숫자가 있으면 탈락, 자기 자신은 패스
		if (puzzle[cur_r][cur_c] == puzzle[cur_r][c] && cur_c != c) {
			return false;
		}
	}
	//같은 박스에 같은 숫자가 있으면 탈락, 자기 자신은 패스
	int box_r = cur_r / 3;
	int box_c = cur_c / 3;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (puzzle[cur_r][cur_c] == puzzle[box_r * 3 + r][box_c * 3 + c] && cur_r != box_r*3+r && cur_c != box_c*3+c) {
				return false;
			}
		}
	}

	//중간에 걸리지 않은 경우 참
	return true;
}

void solve(int size, int cur_size) {
	if (size == cur_size) { //판을 다 채운 경우
		stop = true; //끝남 표시
		// 정답 출력
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				cout << puzzle[r][c] << " ";
			}
			cout << '\n';
		}
		return;
	}

	// 현재 위치 r, c 저장
	int cur_r = blank[cur_size].first;
	int cur_c = blank[cur_size].second;

	for (int i = 1; i <= 9; i++) { 
		puzzle[cur_r][cur_c] = i; //1부터 9까지 대입
		if (is_available(cur_r, cur_c)) { //참이면 다음 빈칸 채우기
			solve(size, cur_size + 1); 
		}
		//빈칸 채우기가 끝나거나 이전 숫자 때문에 다른 빈칸에 어떤 수도 들어갈 수 없는경우
		if (stop == true) { //빈칸 채우기가 끝난 경우
			return;
		}
		puzzle[cur_r][cur_c] = 0; //빈칸을 0으로 만들고 이전에 들어갈 수 있는 다른 숫자를 찾는다.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	//입력
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			cin >> puzzle[r][c];
			if (puzzle[r][c] == 0) {
				blank.push_back(make_pair(r, c));
			}
		}
	}

	solve(blank.size(), 0);


	return 0;
}