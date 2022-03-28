//���̵� : �ǹ�3
//���� : 09:38
//�� : 09:39
#include <iostream>

using namespace std;

int arr[8] = { 0 };

//��Ʈ��ŷ pruning �κ�
bool is_available(int cur) {
	for (int i = 0; i < cur; i++) {
		if (arr[cur] == arr[i] || arr[cur] < arr[i]) { //������ ���� �Ͱ� ��ġ�ų� �� ������ Ż��
			return false;
		}
	}
	return true;
}

//DFS ���� �κ�
void DFS(int N, int M, int cur) {
	if (M == cur) { //������ ����µ� ������ ��� ��� ���
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) { //���ڸ� �־�� �´��� Ȯ��
		arr[cur] = i;
		if (is_available(cur)) {
			DFS(N, M, cur + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	DFS(N, M, 0);

	return 0;
}