//���̵� : �ǹ�3
//���� : 20:08
//�� : 20:35
#include <iostream>

using namespace std;

int dp[11] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;  // 1 = 1
	dp[2] = 2;  // 2 = 1 + 1, 2
	dp[3] = 4;  // 3 = 1 + 1 + 1, 1 + 2, 2 + 1, 3

	// 4���� 10������ ��� ����� �� ����
	for (int i = 4; i < 11; i++) {
		int cnt = 0;
		for (int j = 1; j <= 3; j++) {
			cnt += dp[i - j];
		}
		dp[i] = cnt;
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';  // ������ �� ���
	}

	return 0;
}