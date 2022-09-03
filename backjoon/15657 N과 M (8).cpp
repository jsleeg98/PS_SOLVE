//���̵� : �ǹ�3
//���� : 01:01
//�� : 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[8] = { 0 }; // ��� �迭
int num[8] = { 0 }; // �Է� �迭

// ���� ���ڸ� ���� �ʵ��� Ȯ���ϴ� �Լ�
bool is_available(int cur) {
	for (int i = 0; i < cur; i++) {
		if (arr[i] > arr[cur]) { // ������ �ִٸ�
			return false; // ����
		}
	}
	return true; // ������ ��
}

void DFS(int N, int M, int cur) {
	if (cur == M) { // ������ ���̸�ŭ ����� �� ���
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		arr[cur] = num[i]; // �� ��ġ�� ���� �Ҵ�
		if (is_available(cur)) { // ������ ���ڸ� �Ҵ����� ���� ���
			DFS(N, M, cur + 1); // ���� ���ڸ� ã��
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	DFS(N, M, 0);

	return 0;
}