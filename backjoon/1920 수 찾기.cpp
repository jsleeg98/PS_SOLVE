//���̵� : �ǹ�4
//���� : 11:08
//�� : 11:22
#include <iostream>
#include <algorithm>

using namespace std;

int A[100000]; //�迭�� ����

//Binary Search �˰���
//BS(0, 4, 5)�� �ε��� 0, 1, 2, 3���� 5�� ã�´ٴ� �ǹ�
int BS(int start, int end, int search) { //����, ��, �˻��� ����
	if (end - start == 1 && search == A[start]) { //�迭�� ũ�Ⱑ 1�� ��� ���� �ִ� ���ڰ� �˻��ϴ� ������ Ȯ���Ͽ� ������
		return 1; //1 ��ȯ
	}
	if (end - start == 1 && search != A[start]) { //�˻��ϴ� ���� �ƴϸ�
		return 0; //0 ��ȯ
	}
	if (end - start == 0) { //�迭�� ũ�Ⱑ 0�� ���, ��� �ڵ�
		return 0; //0 ��ȯ
	}

	int medium = (start + end) / 2; //�߰� �ε��� ��
	if (search == A[medium]) { //�߰� �ε����� ���� �˻��ϴ� ���̸�
		return 1; //1 ��ȯ
	}
	else { //�߰� �ε����� ���� �˻��ϴ� ���� �ƴ� ���
		if (search > A[medium]) { //�˻��ϴ� ���� �߰� ������ ū ���
			return BS(medium, end, search); //�����ʿ��� �ٽ� �˻� �����, �̺���
		}
		else if (search < A[medium]) { //�˻��ϴ� ���� �߰� ������ ���� ���
			return BS(start, medium, search); //���ʿ��� �ٽ� �˻� �����, �̺���
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N); //�������� ������ �ݵ�� ���־�� �̺�Ž���� �����ϴ�.
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << BS(0, N, tmp) << '\n';
	}

	return 0;
}