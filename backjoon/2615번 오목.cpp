//난이도 : 실버2
//시작 : 10:50
//끝 : 
#include <iostream>
#include <vector>

using namespace std;

int puzzle[21][21] = { 0 }; //왼쪽, 오른쪽, 위, 아래에 0으로 테두리 만듬
vector<pair<int, int>> white;
vector<pair<int, int>> black;

bool right_check(int r, int c, int color) { //오른쪽으로 오목 확인
	if (puzzle[r][c - 1] == color) { //이전에 검사 했는지 확인
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r][c + i] == color) { //같은 색의 돌의 수 세기
		cnt++;
		i++;
	}
	if (cnt == 5) { //5개일 때만 정답
		return true;
	}
	else {
		return false;
	}
}
bool bottom_check(int r, int c, int color) { //아래로 오목 확인
	if (puzzle[r - 1][c] == color) { //이전에 검사 했는지 확인
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r + i][c] == color) { //같은 색의 돌의 수 세기
		cnt++;
		i++;
	}
	if (cnt == 5) { //5개일 때만 정답
		return true;
	}
	else {
		return false;
	}
}
bool diagonal_down_check(int r, int c, int color) { //왼쪽 대각선 아래로 오목 확인
	if (puzzle[r - 1][c - 1] == color) { //이전에 검사 했는지 확인
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r + i][c + i] == color) { //같은 색의 돌의 수 세기
		cnt++;
		i++;
	}
	if (cnt == 5) { //5개일 때만 정답
		return true;
	}
	else {
		return false;
	}
}

bool diagonal_up_check(int r, int c, int color) { //왼쪽 대각선 위로 오목 확인
	if (puzzle[r + 1][c - 1] == color) {
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r - i][c + i] == color) { //같은 색의 돌의 수 세기
		cnt++;
		i++;
	}
	if (cnt == 5) { //5개일 때만 정답
		return true;
	}
	else {
		return false;
	}
}

vector<pair<int, int>> full_check(int r, int c, int *color) { //전체 경우 체크 함수
	vector<pair<int, int>> result;
	
	if (right_check(r, c, *color)) { //오른쪽 체크
		result.push_back(make_pair(r, c));
		return result;
	}
	else if (bottom_check(r, c, *color)) { //아래 체크
		result.push_back(make_pair(r, c));
		return result;
	}
	else if (diagonal_down_check(r, c, *color)) { //왼쪽 아래 대각선 체크
		result.push_back(make_pair(r, c));
		return result;
	}
	else if (diagonal_up_check(r, c, *color)) { //왼쪽 위 대각선 체크
		result.push_back(make_pair(r, c));
		return result;
	}

	result.push_back(make_pair(-1, -1)); //아무것도 못찾은 경우 
	return result;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	 //입력
	for (int r = 1; r <= 19; r++) {
		for (int c = 1; c <= 19; c++) {
			cin >> puzzle[r][c];
			if (puzzle[r][c] == 1) { //검은 돌 위치 저장
				black.push_back(make_pair(r, c));
			}
			else if (puzzle[r][c] == 2) { //흰 돌 위치 저장
				white.push_back(make_pair(r, c));
			}
		}
	}
	
	int color = 1; //검은 돌
	vector<pair<int, int>> result;
	for (int i = 0; i < black.size(); i++) { //검은 돌에서 오목 확인
		result = full_check(black[i].first, black[i].second, &color);//오목 확인
		if (result[0].first != -1 && result[0].second != -1) { //찾은 경우
			cout << color << '\n';
			cout << result[0].first << " " << result[0].second << '\n';
			return 0; // 종료
		}
	}

	color = 2; //흰 돌
	for (int i = 0; i < white.size(); i++) { //흰 돌에서 오목 확인
		result = full_check(white[i].first, white[i].second, &color);//오목 확인
		if (result[0].first != -1 && result[0].second != -1) { //찾은 경우
			cout << color << '\n';
			cout << result[0].first << " " << result[0].second << '\n';
			return 0; //종료
		}
	}
	
	//승부가 안난 경우
	cout << "0" << '\n';
	

	return 0;
}