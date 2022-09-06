//���̵� : �ǹ�1
//���� : 17:28
//�� :
#include <iostream>
#define MAX 1025

using namespace std;

int matrix[MAX][MAX] = { 0 };
int dp_matrix[MAX][MAX] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			if (j == 1 && i == 1) {
				// 1��1���� �״�� �Ҵ�
				dp_matrix[i][j] = matrix[i][j];
			}
			else {
				// r��c���� dp�� Ȱ���Ͽ� 1�� 1������ r�� c�� ������ �� ����
				dp_matrix[i][j] = dp_matrix[i - 1][j] + dp_matrix[i][j - 1] + matrix[i][j] - dp_matrix[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int sum = 0;
		// y1�� x1�� ���� y2�� x2�������� ���� 1��1������ y2��x2�������� �տ��� 1��1������ y2��x1-1�������� ���� ����
		// 1��1������ y1-1��x2�������� ���� ���� �ߺ����� ���� 1��1������ y1-1��x1-1�������� ���� ���ϸ� �ȴ�.
		sum = dp_matrix[y2][x2] - dp_matrix[y2][x1 - 1] - dp_matrix[y1 - 1][x2] + dp_matrix[y1 - 1][x1 - 1];
		cout << sum << '\n';
	}


	return 0;
}