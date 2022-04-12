//���̵� : ���4
//���� : 22:14
//�� : 22:28
#include <iostream>

using namespace std;

int parent[1000001] = { 0 };

//�θ� ��带 �˾Ƴ��� �Լ�
int getParent(int node) {
	if (parent[node] == node) { //�ڱ� �ڽ��� �θ��� ��� �ڱ� �ڽ� ����
		return node;
	}
	return parent[node] = getParent(parent[node]); //�ڱ� �ڽ��� �θ� �ƴ� ��� ��������� �θ� ã��
}

//�θ� ��带 ��ġ�� �ڵ�
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) { //���� ��� ��ȣ�� ��ģ��.
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

//���� �������� Ȯ���ϴ� �ڵ� 
//�θ� ������ ���� ����
int checkParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) { //�θ� ��尡 ���� ���
		return 1;
	}
	else { //�θ� ��尡 �ٸ� ���
		return 0;
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { //�ڱ� �ڽ��� �θ� ���� �ʱ�ȭ
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 0) {
			if (!checkParent(a, b)) { //���� �θ� �ƴ� ���
				unionParent(a, b); //��ħ
			}
			
		}
		else if (mode == 1) {
			if (checkParent(a, b)) { //���� �θ��� ���
				cout << "YES" << '\n'; //YES ���
			}
			else {//�ٸ� �θ��� ���
				cout << "NO" << '\n'; //NO ���
			}
		}
	}


	return 0;
}