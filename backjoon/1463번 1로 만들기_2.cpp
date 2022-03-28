//���̵� : �ǹ�3
//���� : 20:46
//�� : 20:51
#include <iostream>

using namespace std;

int DP[1000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int X;
	cin >> X;

	//DP���� �ش� ��ȣ�� �Ǳ� ���� �ּ� Ƚ��
	DP[1] = 0; //1�� 0������ ����
	for (int i = 2; i <= X; i++) {
		DP[i] = DP[i - 1] + 1; //�켱 ������ +1 �� ���� DP�� ����
		if (i % 2 == 0) { //2�� ������ ���ٸ� 2�� ������ ���� ���� ������ +1 �� ��� �� �ּҰ����� DP �� ����
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
		if (i % 3 == 0) { //3���� ����� ���ٸ� 3���� ������ ���� ���� ������ +1 �� ��� �� �ּ� ������ DP �� ����
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
	}

	//��� ���
	cout << DP[X] << '\n';


	return 0;
}