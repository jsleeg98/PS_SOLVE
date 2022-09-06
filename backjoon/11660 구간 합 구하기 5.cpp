//난이도 : 실버1
//시작 : 17:28
//끝 :
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
				// 1행1열은 그대로 할당
				dp_matrix[i][j] = matrix[i][j];
			}
			else {
				// r행c열은 dp를 활용하여 1행 1열부터 r행 c열 까지의 합 저장
				dp_matrix[i][j] = dp_matrix[i - 1][j] + dp_matrix[i][j - 1] + matrix[i][j] - dp_matrix[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int sum = 0;
		// y1행 x1열 부터 y2행 x2열까지의 합은 1행1열부터 y2행x2열까지의 합에서 1행1열부터 y2행x1-1열까지의 합을 빼고
		// 1행1열부터 y1-1행x2열까지의 합을 빼고 중복으로 빠진 1행1열부터 y1-1행x1-1열까지의 합을 더하면 된다.
		sum = dp_matrix[y2][x2] - dp_matrix[y2][x1 - 1] - dp_matrix[y1 - 1][x2] + dp_matrix[y1 - 1][x1 - 1];
		cout << sum << '\n';
	}


	return 0;
}