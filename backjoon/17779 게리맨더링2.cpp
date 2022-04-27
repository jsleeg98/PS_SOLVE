//난이도 : 골드4
//시작 : 20:58 - 22:12
//끝 : 20:30 - 21:45
#include <iostream>
#include <algorithm>

using namespace std;

int map[21][21];
int label[21][21];
int N;
int result = 987654321;

void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << label[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
		}
	}
}

//구역 라벨링 하는 함수
void labeling(int x, int y, int d1, int d2) {
	//우선 모든 구역을 5번 구역으로 라벨링 한다.
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			label[r][c] = 5;
		}
	}

	//1번 구역
	int sub = 0;
	for (int r = 1; r < x + d1; r++) {
		if (r >= x) sub++; //행이 x 이상일 때 열의 범위를 하나씩 줄인다
		for (int c = 1; c <= y - sub; c++) {
			label[r][c] = 1;
		}
	}

	//2번 구역
	sub = 0;
	for (int r = 1; r <= x + d2; r++) {
		if (r > x) sub++; //행이 x 보다 클 때 열의 범위를 하나씩 줄인다
		for (int c = y + 1 + sub; c <= N; c++) {
			label[r][c] = 2;
		}
	}

	//3번 구역
	sub = 0;
	for (int r = N; r >= x + d1; r--) {
		if (r < x + d1 + d2) sub++; //행이 x + d1 + d2 보다 작을 때 열의 범위를 하나씩 줄인다
		for (int c = 1; c < y - d1 + d2 - sub; c++) {
			label[r][c] = 3;
		}
	}

	//4번 구역
	sub = 0;
	for (int r = N; r > x + d2; r--) {
		if (r <= x + d1 + d2) sub++; //행이 x + d1 + d2 이하일 때 열의 범위를 하나씩 줄인다
		for (int c = y - d1 + d2 + sub; c <= N; c++) {
			label[r][c] = 4;
		}
	}
}

void calc() {
	int sum_people[6] = { 0 };
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			sum_people[label[r][c]] += map[r][c]; //라벨에 해당하는 곳에 합 저장
		}
	}
	sort(sum_people + 1, sum_people + 6); // 1번 구역부터 5번 구역까지 인구수 정렬
	int diff = sum_people[5] - sum_people[1]; //최대 - 최소
	//cout << diff << '\n';
	result = min(result, diff); //차이의 최소값만 저장
	
}

void solve() {
	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= N - 2; d1++) {
				for (int d2 = 1; d2 <= N - 2; d2++) {
					if (x + d1 > N || y - d1 < 1) continue;
					if (x + d1 + d2 > N || y - d1 + d2 > N) continue;
					if (x + d2 > N || y + d2 > N) continue;
					labeling(x, y, d1, d2);
					//cout << x << " " << y << " " << d1 << " " << d2 << '\n';
					//print();
					calc();
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	
	cout << result << '\n';

	return 0;
}