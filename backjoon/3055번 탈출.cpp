//���� : 23:10
//�� : 24:55
//�� �Ÿ��� ���ؼ� ���� �Ѹ��� ��� �̵��� �� ����ؾ��ϴµ� ��� ���� �ѷ��� ���������� 
//�̴� distance_map�� tree_depth�� �̿��Ͽ� �ذ��Ͽ���.
//tree_depth�� distance_map�� ���� ���� ���� �Ѹ��� �ʵ��� �Ͽ� ���� ��Ȳ���� S�� ��������.
#include <iostream>
#include <string>
#include <queue>

using namespace std;

vector<pair<int, int>> water;

//�� �Ѹ���
//�� �迭, ���� r, ���� c, �� ��ü R, �� ��ü C
void watering(char input_map[51][51], int R, int C) {
	vector<pair<int, int>> tmp_water;
	int dC[4] = { 1, 0, -1, 0 };
	int dR[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < water.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int next_r = water[i].first + dR[j];
			int next_c = water[i].second + dC[j];
			if (next_r > 0 && next_r < R + 1
				&& next_c > 0 && next_c < C + 1) {
				if (input_map[next_r][next_c] == '.') {
					input_map[next_r][next_c] = '*';
					tmp_water.push_back(make_pair(next_r, next_c)); //�� ��ǥ �ӽ� ����, �̷��� ���� ������ �ѹ��� ���� �� �ѷ���
				}
			}

		}
	}
	//�ӽ� �� ��ǥ�� �� �� ��ǥ�� �߰�
	for (int i = 0; i < tmp_water.size(); i++) {
		water.push_back(tmp_water[i]);
	}
}

//�� ���
void print_map(char input_map[51][51], int R, int C) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << input_map[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string line[51];
	char input_map[51][51];
	int visited_map[51][51] = { 0 };
	queue<pair<int, int>> queue;
	int distance_map[51][51] = { 0 };
	int dC[4] = { 1, 0, -1, 0 };
	int dR[4] = { 0, 1, 0, -1 };
	int start_R, start_C, end_R, end_C;
	bool stop = false;
	int tree_depth = -1;

	int R, C;
	cin >> R >> C; //��, �� �Է�

	//���� ���� ���ڿ� �Է�
	for (int i = 1; i <= R; i++) {
		cin >> line[i];
	}

	//�� �Է�
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			input_map[i][j] = line[i][j - 1];
			if (input_map[i][j] == 'S') { //���� ��ǥ �ʱ�ȭ
				start_R = i;
				start_C = j;
				input_map[i][j] = '.';
			}
			else if (input_map[i][j] == 'D') {
				end_R = i;
				end_C = j;
			}
			else if (input_map[i][j] == '*') {
				water.push_back(make_pair(i, j));
			}
		}
	}

	visited_map[start_R][start_C] = 1; //���� ��ġ �湮 ó��
	queue.push(make_pair(start_R, start_C)); //ť�� ��ǥ ����
	while (queue.size() != 0 && stop == false) {
		int r = queue.front().first;
		int c = queue.front().second;
		queue.pop(); //ť���� pop
		input_map[r][c] = '.'; //���� ��ġ . ó��

		if (tree_depth < distance_map[r][c]) {
			watering(input_map, R, C); //�� �Ѹ���
			tree_depth++;
		}
		
		
	
		//print_map(input_map, R, C); //�� ���
		//cout << "-----------------\n"; //���м�
		

		
		//������ �� �ִ� ��ǥ Ȯ��
		for (int i = 0; i < 4; i++) {
			int next_r = r + dR[i];
			int next_c = c + dC[i];
			if (next_r > 0 && next_r < R + 1
				&& next_c > 0 && next_c < C + 1) { //���� �Ѿ�� �ʴ� ���
				if (input_map[next_r][next_c] == '.' || input_map[next_r][next_c] == 'D') { //.�̳� S�� ������ �� �ִ� ���
					if (visited_map[next_r][next_c] == 0) { //�湮���� ���� ���
						distance_map[next_r][next_c] = distance_map[r][c] + 1; //�Ÿ� 1 �߰�
						visited_map[next_r][next_c] = 1; //�湮 ó��
						queue.push(make_pair(next_r, next_c)); //ť�� push

						//input_map[next_r][next_c] = 'S'; //D�� ���� �� �ִ� ��ǥ ǥ��
						if (input_map[next_r][next_c] == 'D') { //S�� ������ ���
							stop = true; //����
							break;
						}
							
					}
				}
			}
		}
		//print_map(input_map, R, C); //�� ���
		//cout << endl;
		
	}

	
	if (stop == true) { //S�� ������ ���
		cout << distance_map[end_R][end_C] << '\n';
	}
	else { //S�� �������� ���� ���
		cout << "KAKTUS" << '\n';
	}
	


	return 0;
}