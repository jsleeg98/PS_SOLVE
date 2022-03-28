//���̵� : ���2
//���� : 15:45
//�� : �ؼ� ����
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[1001] = { 0 };
	int B[1001] = { 0 };
	int C[1001] = { 0 };

	vector<int> D;
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		C[i] = B[i] - A[i];
	}

	//�� �� ����
	int prev = C[0];
	int cnt = 0;

	if (N == 1) {
		cnt = abs(prev);
	}
	else {
		for (int i = 1; i < N; i++) {
			if (C[i] >= 0) {//����� ���
				if (prev < 0){ //������ �����ΰ�� - ��ȣ �ٸ�
					cnt += abs(prev); //���� ���� Ƚ�� ����
					prev = C[i]; //������ ����
				}
				else if (prev < C[i]) { //����� ���������� ���
					prev = C[i]; //������ ����
				}
				else { //�������� ��
					cnt += prev - C[i]; //������� Ƚ�� ����
					prev = C[i]; //���� ����
				}
			}
			else { //������ ���
				if (prev > 0) { //������ ����� ��� - ��ȣ �ٸ�
					cnt += prev; //���� ���� Ƚ���� ����
					prev = C[i]; //������ ����
				}
				else if (prev > C[i]) { //������ ���������� ���
					prev = C[i]; //���� ����
				}
				else { //�������� ��
					cnt += abs(prev) - abs(C[i]); //������� Ƚ�� ����
					prev = C[i]; //���� ����
				}
			}
		}
		//������ ���� �� Ƚ�� �߰�
		cnt += abs(prev);
		cout << cnt << '\n';
	}

	return 0;
}