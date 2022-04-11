//난이도 : 골드5
//시작 : 18:17
//끝 :
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char map[51][51] = { 0 };

int result = 0;

pair<int,int> BFS(int r, int c, int *result) {
	int map_distance[51][51] = { 0 };
	int visited[51][51] = { 0 };
	visited[r][c] = 1;
	map_distance[r][c] = 0;
	queue<pair<int, int>> L;
	L.push(make_pair(r, c));
	int tmp_result = 0;
	pair<int, int> far;
	
	while (!L.empty()) {
		int r = L.front().first;
		int c = L.front().second;
		L.pop();
		int cur_distance = map_distance[r][c];
		for (int i = 0; i < 4; i++) {
			if (map[r + dir[i][0]][c + dir[i][1]] == 'L') {
				if (visited[r + dir[i][0]][c + dir[i][1]] == 0) {
					visited[r + dir[i][0]][c + dir[i][1]] = 1;
					L.push(make_pair(r + dir[i][0], c + dir[i][1]));
					map_distance[r+dir[i][0]][c+dir[i][1]] = cur_distance + 1;
					far.first = r + dir[i][0];
					far.second = c + dir[i][1];
					tmp_result = cur_distance + 1;
				}
			}
		}
	}
	//cout << tmp_result-1 << '\n';
	if (tmp_result > *result) {
		*result = tmp_result;
	}
	//cout << far.first << " " << far.second << '\n';

	return far;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	
	queue<pair<int, int>> L;
	int r, c;
	cin >> r >> c;
	// map 입력
	for (int i = 1; i <= r; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++) {
			map[i][j + 1] = tmp[j]; //열 인덱스 1부터 시작
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == 'L') {
				BFS(i, j, &result);
			}
		}
	}


	cout << result << '\n';



	return 0;
}