//���̵� : �ǹ�2
//���� : 10:50
//�� : 
#include <iostream>
#include <vector>

using namespace std;

int puzzle[21][21] = { 0 }; //����, ������, ��, �Ʒ��� 0���� �׵θ� ����
vector<pair<int, int>> white;
vector<pair<int, int>> black;

bool right_check(int r, int c, int color) { //���������� ���� Ȯ��
	if (puzzle[r][c - 1] == color) { //������ �˻� �ߴ��� Ȯ��
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r][c + i] == color) { //���� ���� ���� �� ����
		cnt++;
		i++;
	}
	if (cnt == 5) { //5���� ���� ����
		return true;
	}
	else {
		return false;
	}
}
bool bottom_check(int r, int c, int color) { //�Ʒ��� ���� Ȯ��
	if (puzzle[r - 1][c] == color) { //������ �˻� �ߴ��� Ȯ��
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r + i][c] == color) { //���� ���� ���� �� ����
		cnt++;
		i++;
	}
	if (cnt == 5) { //5���� ���� ����
		return true;
	}
	else {
		return false;
	}
}
bool diagonal_down_check(int r, int c, int color) { //���� �밢�� �Ʒ��� ���� Ȯ��
	if (puzzle[r - 1][c - 1] == color) { //������ �˻� �ߴ��� Ȯ��
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r + i][c + i] == color) { //���� ���� ���� �� ����
		cnt++;
		i++;
	}
	if (cnt == 5) { //5���� ���� ����
		return true;
	}
	else {
		return false;
	}
}

bool diagonal_up_check(int r, int c, int color) { //���� �밢�� ���� ���� Ȯ��
	if (puzzle[r + 1][c - 1] == color) {
		return false;
	}
	int cnt = 0;
	int i = 0;
	while (puzzle[r - i][c + i] == color) { //���� ���� ���� �� ����
		cnt++;
		i++;
	}
	if (cnt == 5) { //5���� ���� ����
		return true;
	}
	else {
		return false;
	}
}

vector<pair<int, int>> full_check(int r, int c, int *color) { //��ü ��� üũ �Լ�
	vector<pair<int, int>> result;
	
	if (right_check(r, c, *color)) { //������ üũ
		result.push_back(make_pair(r, c));
		return result;
	}
	else if (bottom_check(r, c, *color)) { //�Ʒ� üũ
		result.push_back(make_pair(r, c));
		return result;
	}
	else if (diagonal_down_check(r, c, *color)) { //���� �Ʒ� �밢�� üũ
		result.push_back(make_pair(r, c));
		return result;
	}
	else if (diagonal_up_check(r, c, *color)) { //���� �� �밢�� üũ
		result.push_back(make_pair(r, c));
		return result;
	}

	result.push_back(make_pair(-1, -1)); //�ƹ��͵� ��ã�� ��� 
	return result;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	 //�Է�
	for (int r = 1; r <= 19; r++) {
		for (int c = 1; c <= 19; c++) {
			cin >> puzzle[r][c];
			if (puzzle[r][c] == 1) { //���� �� ��ġ ����
				black.push_back(make_pair(r, c));
			}
			else if (puzzle[r][c] == 2) { //�� �� ��ġ ����
				white.push_back(make_pair(r, c));
			}
		}
	}
	
	int color = 1; //���� ��
	vector<pair<int, int>> result;
	for (int i = 0; i < black.size(); i++) { //���� ������ ���� Ȯ��
		result = full_check(black[i].first, black[i].second, &color);//���� Ȯ��
		if (result[0].first != -1 && result[0].second != -1) { //ã�� ���
			cout << color << '\n';
			cout << result[0].first << " " << result[0].second << '\n';
			return 0; // ����
		}
	}

	color = 2; //�� ��
	for (int i = 0; i < white.size(); i++) { //�� ������ ���� Ȯ��
		result = full_check(white[i].first, white[i].second, &color);//���� Ȯ��
		if (result[0].first != -1 && result[0].second != -1) { //ã�� ���
			cout << color << '\n';
			cout << result[0].first << " " << result[0].second << '\n';
			return 0; //����
		}
	}
	
	//�ºΰ� �ȳ� ���
	cout << "0" << '\n';
	

	return 0;
}