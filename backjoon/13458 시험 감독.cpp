//���̵� : �����2
//���� : 19:52
//�� : 20:24
#include <iostream>

using namespace std;

int A[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int B, C;
	cin >> B >> C;

	long long int cnt = 0; //�������� ���� int ������ �Ѿ�� ��찡 �ִ�.
	// N = 1000000
	// A�� ��� 1000000�̰� B, C�� 1�� ��� �Ѿ��

	for (int i = 0; i < N; i++) {
		cnt++; // �� ������ 1�� ī��Ʈ
		if (A[i] - B > 0) {
			int tmp = (A[i] - B) / C;
			cnt += tmp;
			if ((A[i] - B) % C > 0) {
				cnt++; //�������� �ִ� ��� �ΰ����� �Ѹ� �߰�
			}
		}
	}


	cout << cnt << '\n';

	return 0;
}