//���̵� : �ǹ�3
//���� : 17:25
//�� : 17:35
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Ǻ���ġ ���� ���� �迭
	//90�� �Ǹ� int�� ������ �Ѿ�� ������ long long int ���
	long long int DP[91];
	int N;
	cin >> N;
	DP[1] = 1; //���̰� 1�� ���� 1 �ۿ� ����
	DP[2] = 1; //���̰� 2�� ���� 10 �ۿ� ����
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[N] << '\n';

	return 0;
}