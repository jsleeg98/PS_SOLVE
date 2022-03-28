//���̵� : �ǹ�2
//���� : 17:03
//�� : 17:34
#include <iostream>

using namespace std;

int dp[101][101][101] = { 0 }; //�κ� ���� ���� �迭

int w(int a, int b, int c) {
	if (dp[a][b][c] != 0) { //�̹� �κ� ������ �ִٸ� �ٷ� �κ� ���� ����
		return dp[a][b][c];
	}
	if (a <= 50 || b <= 50 || c <= 50) { //0���� 100������ -50���� 50���� ����ϱ� ������ +50�� �Ͽ���.
		
		return dp[a][b][c] = 1; //�κ� ���� ���� �迭�� �����ϸ鼭 ����
	}
	if (a > 70 || b > 70 || c > 70) { //0���� 100������ -50���� 50���� ����ϱ� ������ +50�� �Ͽ���.
		return dp[a][b][c] = w(70, 70, 70); //�κ� ���� ���� �迭�� �����ϸ鼭 ����
	}
	if (a < b && b < c) {
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); //�κ� ���� ���� �迭�� �����ϸ鼭 ���� 
	}
	return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); //�κ� ���� ���� �迭�� �����ϸ鼭 ����
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		else {
			cout << "w(" << a << ", " << b << ", " << c << ") = ";
			
			cout << w(a + 50, b + 50, c + 50) << '\n';
		}
	}

	return 0;
}