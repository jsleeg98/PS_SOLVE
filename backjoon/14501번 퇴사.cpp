//���� : 20:50
//�� : 21:06
#include <iostream>
#include <vector>
#include <algorithm> //max

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T[16]; //�ɸ��� �ϼ�
	int P[16]; //����
	int DP[17] = { 0 }; //DP �迭 ���� ���� �������� ���� ������ ��
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i + 1] >> P[i + 1]; //�ϰ� �ε����� ���� ������
	}

	for (int i = N; i >= 1; i--) {
		//����Ϻ��� ���� �ʰ� ���� ���� �� �� ���°��
		if (i + T[i] > N + 1) { 
			//���� ���� ������ ���ϱ� ������ ���� ���� ����.
			DP[i] = DP[i + 1]; 
		}
		else { //���� ���� �� �� �ִ� ���
			//���� ���� �ʴ� ���� ���� �ϴ� ��츦 ���� �ִ� ���� ���Ѵ�.
			DP[i] = max(DP[i + 1], P[i] + DP[i + T[i]]);
		}
	}

	//ù���� ���� ������ ���� ����Ǿ� �̸� ���
	cout << DP[1] << '\n'; 

	return 0;
}
