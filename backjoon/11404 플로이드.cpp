//���̵� : ���4
//���� : 09:26
//�� : 09:46
#include <iostream>
#include <limits>

using namespace std;

#define INF 100000000 //���� �� ����

int dp[101][101] = { 0 };

//n�� ������ ����
void floyd_warshall(int n) {
	// k : ��ó���� ����
	for (int k = 1; k <= n; k++) {
		// i : ���� ����
		for (int i = 1; i <= n; i++) {
			// j : ���� ����
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) { //k�� ��ó���� ���� ����� �� ��ٸ� �� ����
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//��� ��θ� �������� �ʱ�ȭ
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dp[i][j] = INF;
		}
	}

	int n, m;
	cin >> n >> m;

	//�ڱ� �ڽ��� ����, �������� ������ �Ÿ��� 0�̴�.
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dp[a][b] > c) { // �ּ� �Ÿ��� ���� //���� ������ �����ϴ� �뼱�� �ϳ��� �ƴ� �� �ֱ� ����
			dp[a][b] = c;
		}
	}

	// �÷��̵�-���� �˰��� ����
	floyd_warshall(n);

	//��� ���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INF) { //������ �� �� ���� ���
				dp[i][j] = 0; //0���� ���
				cout << dp[i][j] << " ";
			}
			else {
				cout << dp[i][j] << " ";
			}
		}
		cout << '\n';
	}


	return 0;
}