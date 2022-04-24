//���̵� : ���4
//���� : 14:50
//�� :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K; //ũ��, ���� ��, ��
int map[10][10]; //��� ��
int S2D2[10][10]; //�ʱ� ��� //�ܿ︶�� �߰�
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<pair<pair<int, int>, int>> live_tree; //����ִ� ���� ����
vector<pair<pair<int, int>, int>> dead_tree; //���� ���� ����
vector<pair<pair<int, int>, int>> retrive_tree; //���� ���� ����
vector<int> tree_map[10][10]; //���� ���� ���� ��

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
	live_tree.clear(); //�� Ʈ�� ���� �ʱ�ȭ
	dead_tree.clear(); //���� Ʈ�� ���� �ʱ�ȭ
	retrive_tree.clear(); //���� Ʈ�� ���� �ʱ�ȭ

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (tree_map[r][c].size() == 0) continue;
			sort(tree_map[r][c].begin(), tree_map[r][c].end()); //���̼� ��������

			for (int i = 0; i < tree_map[r][c].size(); i++) {
				if (tree_map[r][c][i] <= map[r][c]) { //����� ���� �� �ִ� ���
					map[r][c] -= tree_map[r][c][i]; //��� ����
					int age = tree_map[r][c][i] + 1; //���� +1
					tree_map[r][c][i] += 1; //���� +1
					if (age % 5 == 0) {
						retrive_tree.push_back({ {r, c}, age }); //���� Ʈ�� �߰�
					}
					live_tree.push_back({ {r, c}, age }); //����ִ� Ʈ�� �߰�
				}
				else {
					dead_tree.push_back({ {r, c}, tree_map[r][c][i]}); //���� Ʈ�� �߰�
				}
			}
			tree_map[r][c].clear(); //���� ��ġ ���� ���� �ʱ�ȭ //������ �ٽ� ������ �ٰ�
		}
	}
	
	//print();
}

void summer() {
	for (int i = 0; i < dead_tree.size(); i++) {
		int r = dead_tree[i].first.first;
		int c = dead_tree[i].first.second;
		map[r][c] += dead_tree[i].second / 2; //���� ���� ���� /2 ��� �߰�
	}
}

void fall() {
	//���� ���� ���͸� ���� ������ �������� live_tree ���ͷ� �߰�
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

	//live_tree ���Ϳ� �ִ� �������� tree_map ���Ϳ� ���̸� �߰�
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
			map[r][c] = 5; //ó�� ��� 5�� �ʱ�ȭ
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