//���̵� : ���5
//���� : 12:08 - 13:00
//�� : 14:54 - 15:30
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�迭�� ũ�Ⱑ ũ�� ������ ���������� ����
int DP[100001][101] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w[101] = { 0 }; //���� ���� �迭
	int v[101] = { 0 }; //��ġ ���� �迭

	int N, K; 
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}

	//i�� ������ ���� ����, j�� ���� ��ȣ
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (i >= w[j]) { // �ش� ������ ���� �� �ִ� ���
				//������ ��� ���� ���Է� ���� �� �ִ� ���� ��ġ�� ������ ���� ���� ��츦 ���Ͽ�
				//���� ��ġ�� ����
				DP[i][j] = max(v[j] + DP[i - w[j]][j - 1], DP[i][j - 1]);
			}
			else { //������ ���� �� ���� ��� ���� ���� ������ �ִ� ��ġ�� ����
				DP[i][j] = DP[i][j - 1];
			}
		}
	}

	//���� ���Կ� ���� ��� ������ ���� ���� �ִ� ��ġ ���
	cout << DP[K][N] << '\n';

	return 0;
}