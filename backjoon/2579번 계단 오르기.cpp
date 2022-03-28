//���̵� : �ǹ�3
//���� : 17:50
//�� : 18:36
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int stair[301] = { 0 }; //��� ���� ���� �迭
	int DP[301] = { 0 }; //DP ���� �迭
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	
	DP[1] = stair[1]; //����� 1���� �� ���� �� ����
	DP[2] = stair[1] + stair[2]; //����� 2�� �϶� ���� �� ����

	for (int i = 3; i <= N; i++) { //����� 3�� �̻��� �� ���� �� ����
		//���� ����� ��´ٴ� �����Ͽ�
		//������� ��� ����������� ��� ���� ��������� ��� ��� �� ū ���� ���Ͽ� ����
		DP[i] = max(stair[i] + stair[i - 1] + DP[i - 3], stair[i] + DP[i-2]);
	}

	cout << DP[N] << '\n'; //���� ����� ���� ���� �� ���
	


	return 0;
}