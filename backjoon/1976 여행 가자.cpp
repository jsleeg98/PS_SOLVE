//���̵� : ���4
//���� : 
//�� :
#include <iostream>

using namespace std;

int parent[201]; //�θ� ��带 ����

//�θ� ��带 ��������� ã���鼭 �ٲ��ش�.
int getParent(int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = getParent(parent[n]); //ã���鼭 �ٲ�����Ѵ�. 
	}
}

//���� �θ� ������� Ȯ��
int checkParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}

//�θ� ��带 ��ħ
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b); 
	if (!checkParent(a, b)) { //�θ� ��尡 �ٸ����
		if (a < b) { //��� ��ȣ�� �� ���� ������ ����
			parent[b] = a;
		}
		else {
			parent[a] = b;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;

	//�θ� ��� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	//���� ���°� 1�̶�� ��ħ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int state;
			cin >> state;
			if (state) {
				unionParent(i, j);
			}
		}
	}

	//ù��° ���� ��� ��ȣ�� �θ� ����
	int tmp_node;
	cin >> tmp_node;
	int result = parent[tmp_node];
	int result_state = 1;
	//�������� ������ ��� ��ȣ�� �θ� �ľ��Ͽ� ������ �ٸ��� �ٷ� ����
	for (int i = 2; i <= M; i++) {
		cin >> tmp_node;
		if (parent[tmp_node] != result) {
			result_state = 0;
			break;
		}
	}

	//1�̸� �θ� ��� ��ȣ�� �� ���� ��
	if (result_state == 1) {
		cout << "YES" << '\n';
	}
	else { //0�̸� �θ� ��� ��ȣ�� �ٸ��� �ִ� ��
		cout << "NO" << '\n';
	}

	return 0;
}