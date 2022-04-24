//난이도 : 골드4
//시작 : 14:50
//끝 :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K; //크기, 나무 수, 해
int map[10][10]; //양분 맵
int S2D2[10][10]; //초기 양분 //겨울마다 추가
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<pair<pair<int, int>, int>> live_tree; //살아있는 나무 벡터
vector<pair<pair<int, int>, int>> dead_tree; //죽은 나무 벡터
vector<pair<pair<int, int>, int>> retrive_tree; //번식 나무 벡터
vector<int> tree_map[10][10]; //나이 벡터 저장 맵

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << map[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}



void spring() {
	live_tree.clear(); //산 트리 벡터 초기화
	dead_tree.clear(); //죽은 트리 벡터 초기화
	retrive_tree.clear(); //번식 트리 벡터 초기화

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (tree_map[r][c].size() == 0) continue;
			sort(tree_map[r][c].begin(), tree_map[r][c].end()); //나이순 오름차순

			for (int i = 0; i < tree_map[r][c].size(); i++) {
				if (tree_map[r][c][i] <= map[r][c]) { //양분을 먹을 수 있는 경우
					map[r][c] -= tree_map[r][c][i]; //양분 빼기
					int age = tree_map[r][c][i] + 1; //나이 +1
					tree_map[r][c][i] += 1; //나이 +1
					if (age % 5 == 0) {
						retrive_tree.push_back({ {r, c}, age }); //번식 트리 추가
					}
					live_tree.push_back({ {r, c}, age }); //살아있는 트리 추가
				}
				else {
					dead_tree.push_back({ {r, c}, tree_map[r][c][i]}); //죽은 트리 추가
				}
			}
			tree_map[r][c].clear(); //현재 위치 나이 벡터 초기화 //가을에 다시 설정해 줄것
		}
	}
	
	//print();
}

void summer() {
	for (int i = 0; i < dead_tree.size(); i++) {
		int r = dead_tree[i].first.first;
		int c = dead_tree[i].first.second;
		map[r][c] += dead_tree[i].second / 2; //죽은 나무 나이 /2 양분 추가
	}
}

void fall() {
	//번식 나무 벡터를 통해 번식한 나무들을 live_tree 벡터로 추가
	for (int i = 0; i < retrive_tree.size(); i++) {
		int cr = retrive_tree[i].first.first;
		int cc = retrive_tree[i].first.second;
		for (int j = 0; j < 8; j++) {
			int nr = cr + dr[j];
			int nc = cc + dc[j];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			live_tree.push_back({ {nr, nc}, 1 });
			
		}
	}

	//live_tree 벡터에 있는 나무들을 tree_map 벡터에 나이만 추가
	for (int i = 0; i < live_tree.size(); i++) {
		int r = live_tree[i].first.first;
		int c = live_tree[i].first.second;
		int age = live_tree[i].second;
		tree_map[r][c].push_back(age);
	}
}

void winter() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			map[r][c] += S2D2[r][c];
		}
	}
	
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			map[r][c] = 5; //처음 양분 5로 초기화
		}
	}


	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> S2D2[r][c];
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		tree_map[r-1][c-1].push_back(age);
	}

	int year = 0;
	while (1) {
		spring();
		summer();
		fall();
		winter();
		year++;
		if (year == K) {
			break;
		}
	}

	

	cout << live_tree.size() << '\n';
	


	return 0;
}