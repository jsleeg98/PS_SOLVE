//���̵� : �ǹ� 2
//���� : 19:17
//�� : 21:03
#include <iostream>
#include <vector>

using namespace std;


int parent[100001] = { 0 };  // ��� �θ� ��� ��ȣ�� 0���� �ʱ�ȭ
vector<int> children[100001];  // �ڽ� ������ �����ϴ� ���� �迭

//  �θ� ��带 ��������� �����ϴ� �Լ�
void set_parent(int node) {
	for (int i = 0; i < children[node].size(); i++) {
		if(parent[children[node][i]] == 0){  // �θ� ��尡 �������� ���� ���
			parent[children[node][i]] = node;  // �θ� ��� ����
			set_parent(children[node][i]);  // ��������� �ڽ� ��忡 �θ� ��� ����
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	parent[1] = 1;  // 1�� ���� ��Ʈ ���� ����

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b; 
		cin >> a >> b;
		if (parent[a] != 0) {  // a�� �θ� ��尡 �̹� ������ ���
			parent[b] = a;
			if (children[b].size() > 0) {
				set_parent(b);
			}
		}
		else if (parent[b] != 0) {  // b�� �θ� ��尡 �̹� ������ ���
			parent[a] = b;
			if (children[a].size() > 0) {
				set_parent(a);
			}
		}
		else {  // a, b �Ѵ� �θ� ��尡 �̹� �����Ǿ� ���� ���� ���
			children[a].push_back(b);  // �ڽ� ���� �켱 ����
			children[b].push_back(a);  // �ڽ� ���� �켱 ����
		}
	}

	// ��� ���
	for (int i = 2; i < N + 1; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}