//난이도 : 골드5
//시작 : 
//끝 :
#include <iostream>

using namespace std;

int queen_col[15] = {0};
int cnt = 0;

//현재 들어온 열 값이 가능한지 여부 판단
bool is_available(int current_row) {
	for (int row = 0; row < current_row; row++) {
		// 같은 열에 있어도 안되고, 대각선이 있어도 안된다.
		if ((queen_col[row] == queen_col[current_row]) || (current_row - row == abs(queen_col[current_row] - queen_col[row]))) {
			return false;
		}
	}
	return true;
}

void nqueen(int N, int current_row) {
	if (current_row == N) { //끝까지 다 놓은 경우 성공
		cnt++; //개수 +1
		return;
	}
	for (int col = 0; col < N; col++) {
		queen_col[current_row] = col; //현재 행에 후보 열을 놓아보고
		if (is_available(current_row)) {
			nqueen(N, current_row + 1); //가능하면 DFS
		}//안되면 후보 열 전체 탈락
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	nqueen(N, 0 );
	cout << cnt << '\n';

	return 0;
}