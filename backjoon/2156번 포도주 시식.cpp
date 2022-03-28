//���̵� : �ǹ�1
//���� : 23:20
//�� : 23:41
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[10001] = { 0 }; //������ �� ���� �迭
	int DP[10000] = { 0 }; //DP �迭
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	DP[1] = A[1]; //DP �ʱ�ȭ - 1���� ���� ���� �� ���ô°� �ִ�
	DP[2] = A[1] + A[2]; //DP �ʱ�ȭ - 2���� ���� ���� �� ���ô°� �ִ�
	for (int i = 3; i <= N; i++) { //3�ܺ��� DP
		//�ִ밪 - ���� ���� ���ð� �� ���� ���ð� ������ �ܿ� ���� DP vs ���� ���� ���ð� ���� �ܿ� ���� DP vs ���� ���� �ȸ��ð� �� �ܿ� ���� DP
		DP[i] = max(A[i] + A[i - 1] + DP[i - 3], max(A[i] + DP[i - 2], DP[i - 1]));
	}

	//�ִ� �� ���
	cout << DP[N] << '\n';

	return 0;
}