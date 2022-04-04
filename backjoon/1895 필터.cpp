//���̵� : �ǹ�4
//���� : 09:33
//�� : 09:45
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> result; //��� ���� �迭
	int img[40][40] = { 0 }; //�Է� �̹��� ���� �迭
	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> img[i][j];
		}
	}
	int T;
	cin >> T;

	for (int i = 0; i < R - 2; i++) {
		for (int j = 0; j < C - 2; j++) {
			int filter[9] = { 0 };
			int cnt = 0;
			for (int k_i = 0; k_i < 3; k_i++) { //3x3 ũ��� filter�� ����
				for (int k_j = 0; k_j < 3; k_j++) {
					filter[cnt] = img[i + k_i][j + k_j];
					cnt++;
				}
			}
			sort(filter, filter + 9); //����
			result.push_back(filter[4]); //�߾Ӱ� ��� ���Ϳ� ����
		}
	}

	int result_cnt = 0;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] >= T) { //T���� ū ���� �� ����
			result_cnt++;
		}
	}

	cout << result_cnt << '\n';
	return 0;
}