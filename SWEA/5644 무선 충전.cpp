//시작 : 14:50
//끝 : 16:10
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int M, A;
int user[2][100];
int BC[8][4];

//BC 번호, 충전량
vector<pair<int, int>> map[10][10];
int charge[2][101];
int dr[5] = { 0, -1, 0, 1, 0 };
int dc[5] = { 0, 0, 1, 0, -1 };

void init() {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			map[x][y].clear();
		}
	}

}

void input() {
	cin >> M >> A;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < M; j++) {
			cin >> user[i][j];
		}
	}

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> BC[i][j];
		}
	}
}

bool cmp_pair(pair<int, int> a, pair<int, int> b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first < b.second) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void BC_map() {
	for (int i = 0; i < A; i++) {
		int x = BC[i][0] - 1;
		int y = BC[i][1] - 1;
		int c = BC[i][2];
		int p = BC[i][3];

		for (int dx = (-1) * c; dx <= c; dx++) {
			for (int dy = (-1) * c; dy <= c; dy++) {
				if (abs(dx) + abs(dy) > c) continue; 
				if (y + dy < 0 || y + dy >= 10 || x + dx < 0 || x + dx >= 10) continue;
				map[y + dy][x + dx].push_back({ i, p });
			}
		}
	}

	//충전량 많은 순으로 맵 정렬
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (map[x][y].size() > 1) {
				sort(map[x][y].begin(), map[x][y].end(), cmp_pair);
			}
		}
	}
}

void check(int cr_1, int cc_1, int cr_2, int cc_2, int time) {
	int bc_1 = -1;
	int bc_2 = -1;
	vector<pair<int, int>> a = map[cr_1][cc_1];
	vector<pair<int, int>> b = map[cr_2][cc_2];
	if (a.size() > 0) {
		bc_1 = a[0].first;
		charge[0][time] = a[0].second;
	}
	else {
		charge[0][time] = 0;
	}
	if (b.size() > 0) {
		bc_2 = b[0].first;
		charge[1][time] = b[0].second;
	}
	else {
		charge[1][time] = 0;
	}
	if (bc_1 == -1 || bc_2 == -1) {
		return;
	}
	

	if (bc_1 != bc_2) {
		charge[0][time] = a[0].second;
		charge[1][time] = b[0].second;
	}
	else {
		if (a.size() == 1 && b.size() == 1) {
			charge[0][time] = a[0].second / 2;
			charge[1][time] = b[0].second / 2;
		}
		else if (a.size() > 1 && b.size() == 1) {
			charge[0][time] = a[1].second;
		}
		else if (a.size() == 1 && b.size() > 1) {
			charge[1][time] = b[1].second;
		}
		else if (a.size() > 1 && b.size() > 1) {
			int a_2 = a[1].second;
			int b_2 = b[1].second;
			if (a_2 > b_2) {
				charge[0][time] = a[1].second;
			}
			else {
				charge[1][time] = b[1].second;
			}
		}
	}
	
}

void move() {
	int cr_1 = 0;
	int cc_1 = 0;
	int cr_2 = 9;
	int cc_2 = 9;

	check(cr_1, cc_1, cr_2, cc_2, 0);

	for (int i = 0; i < M; i++) {
		int dir_num_1 = user[0][i];
		int dir_num_2 = user[1][i];
		int nr_1 = cr_1 + dr[dir_num_1];
		int nc_1 = cc_1 + dc[dir_num_1];
		int nr_2 = cr_2 + dr[dir_num_2];
		int nc_2 = cc_2 + dc[dir_num_2];
		check(nr_1, nc_1, nr_2, nc_2, i + 1);
		cr_1 = nr_1;
		cc_1 = nc_1;
		cr_2 = nr_2;
		cc_2 = nc_2;
	}
}

int charge_sum() {
	int a = 0;
	int b = 0;
	for (int i = 0; i < M + 1; i++) {
		a += charge[0][i];
		b += charge[1][i];
	}
	return a + b;
}

void print() {
	for (int i = 0; i < M + 1; i++) {
		cout << charge[0][i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < M + 1; i++) {
		cout << charge[1][i] << " ";
	}
	cout << '\n';
}

void print_map() {
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			if (map[r][c].size() > 0) {
				cout << map[r][c][0].second << " ";
			}
			else {
				cout << "-" << " ";
			}
		}
		cout << '\n';
	}
	cout << '\n';
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
		BC_map();
		//print_map();
		move();
		//print();
		int result = charge_sum();
		cout << "#" << test_case << " " << result << '\n';
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}