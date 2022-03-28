//���� : 11:04
//��: 11:17

#include <iostream>

using namespace std;

int dp[1001] = {0};

int dp_solve(int n) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		//10007�� ����� ����� �������� ������ int�� �Ѿ�� ����ε� ��� �Ұ���
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; 
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << dp_solve(n) << '\n';
	return 0;
}