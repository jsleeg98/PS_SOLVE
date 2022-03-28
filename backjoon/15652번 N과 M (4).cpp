//���̵� : �ǹ�3
//���� : 10:20
//�� : 10:33
#include <iostream>

using namespace std;

int arr[9] = { 0 }; //���� ���� �迭

//��Ʈ��ŷ pruning ����
bool is_available(int cur) { 
	for (int i = 0; i < cur; i++) {
		if (arr[cur] < arr[i]) { //������������ �� ��� Ż��
			return false;
		}
	}
	return true;
}

//DFS Ž��
void DFS(int N, int M, int cur) {
	if (M == cur) { //������ �ϼ��� ���
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[cur] = i;
		if (is_available(cur)) { //pruning
			DFS(N, M, cur + 1); //���� Ž��
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