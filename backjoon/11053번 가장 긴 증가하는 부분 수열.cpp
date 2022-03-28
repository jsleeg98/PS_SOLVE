//���̵� : �ǹ�2
//���� : 23:50
//�� : 00:24
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[1001] = { 0 };
	int DP[1001] = { 0 };
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	DP[1] = 1;
	for (int i = 2; i <= N; i++) { //�ڽ��� �����ϴ� ��� ���� �� ���� ���� ���̸� DP�� ����
		int tmp_dp = 0; //�ڽ� ���� ���� ������ ���� �� ������ ���� ����
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) { //�ڽ� ���� ���� ���
				if (tmp_dp < DP[j]) { //���� �ִ� ���̺��� �� �� ���
					tmp_dp = DP[j];
				}
			}
		}
		DP[i] = tmp_dp + 1; //�ڱ� �ڽ��� �����ؾ� �ϹǷ� +1
	}

	//DP������ �ִ� ���� ���� �� ���� �����̴�. �� ������ ������ ���� ���� ���� �� ���� �� ������ DP�� �����߱� �����̴�.
	int maxn = DP[0];
	for (int i = 1; i <= N; i++) {
		if (maxn < DP[i]) {
			maxn = DP[i];
		}
	}


	cout << maxn << '\n';

	return 0;
}