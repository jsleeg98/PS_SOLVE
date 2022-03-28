//���̵� : ���4
//���� : 10:40 - 11:48
//�� :
#include <iostream>
#include <vector>
 
using namespace std;

int puzzle[9][9] = { 0 }; //������ ���� ���� �迭
vector<pair<int, int>> blank; //�� ĭ ��ġ ���� ����
bool stop = false; //���� ǥ��

//pruning ����
bool is_available(int cur_r, int cur_c) {
	for (int r = 0; r < 9; r++) { //���� �࿡ ���� ���ڰ� ������ Ż��, �ڱ� �ڽ��� �н�
		if (puzzle[cur_r][cur_c] == puzzle[r][cur_c] && cur_r != r) {
			return false;
		}
	}
	for (int c = 0; c < 9; c++) { //���� ���� ���� ���ڰ� ������ Ż��, �ڱ� �ڽ��� �н�
		if (puzzle[cur_r][cur_c] == puzzle[cur_r][c] && cur_c != c) {
			return false;
		}
	}
	//���� �ڽ��� ���� ���ڰ� ������ Ż��, �ڱ� �ڽ��� �н�
	int box_r = cur_r / 3;
	int box_c = cur_c / 3;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (puzzle[cur_r][cur_c] == puzzle[box_r * 3 + r][box_c * 3 + c] && cur_r != box_r*3+r && cur_c != box_c*3+c) {
				return false;
			}
		}
	}

	//�߰��� �ɸ��� ���� ��� ��
	return true;
}

void solve(int size, int cur_size) {
	if (size == cur_size) { //���� �� ä�� ���
		stop = true; //���� ǥ��
		// ���� ���
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				cout << puzzle[r][c] << " ";
			}
			cout << '\n';
		}
		return;
	}

	// ���� ��ġ r, c ����
	int cur_r = blank[cur_size].first;
	int cur_c = blank[cur_size].second;

	for (int i = 1; i <= 9; i++) { 
		puzzle[cur_r][cur_c] = i; //1���� 9���� ����
		if (is_available(cur_r, cur_c)) { //���̸� ���� ��ĭ ä���
			solve(size, cur_size + 1); 
		}
		//��ĭ ä��Ⱑ �����ų� ���� ���� ������ �ٸ� ��ĭ�� � ���� �� �� ���°��
		if (stop == true) { //��ĭ ä��Ⱑ ���� ���
			return;
		}
		puzzle[cur_r][cur_c] = 0; //��ĭ�� 0���� ����� ������ �� �� �ִ� �ٸ� ���ڸ� ã�´�.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	//�Է�
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