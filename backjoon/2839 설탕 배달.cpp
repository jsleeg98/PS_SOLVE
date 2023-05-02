//���̵� : �ǹ�4
//���� : 20:12
//�� : 20:30
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> DP;
	//5ų�α׷����� �ּ��� ������ �� �ʱ�ȭ
	DP.push_back(-1);  //index 0
	DP.push_back(-1);  //index 1
	DP.push_back(-1);  //index 2
	DP.push_back(1);  //index 3
	DP.push_back(-1);  //index 4
	DP.push_back(1);  //index 5
	
	int N;
	cin >> N;
	for (int i = 6; i <= N; i++) {
		int A = DP[i - 3]; // 3ų�α׷� ������ ���� �� �ִ� ����� �ּ��� ���� ����
		int B = DP[i - 5]; // 5ų�α׷� ������ ���� �� �ִ� ����� �ּ��� ���� ����
		if (A == -1 && B == -1) {  // �� �� ���� �� ���� ���
			DP.push_back(-1); 
		}
		else if (A == -1 && B != -1) {  // 5ų�α׷� ������ ���� �� �ִ� ��� ���� �ּ��� ���� �� +1
			DP.push_back(B + 1);
		}
		else if (A != -1 && B == -1) {  // 3ų�α׷� ������ ���� �� �ִ� ��� ���� �ּ��� ���� �� +1
			DP.push_back(A + 1);
		}
		else {
			DP.push_back(min(A + 1, B + 1));  // �� �� ���� �� �ִ� ��� ���� �ּ��� ���� �� �� ���� ���� �� +1
		}
	}
	cout << DP[N] << '\n';

	return 0;
}