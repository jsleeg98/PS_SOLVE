//���̵� : �ǹ�1
//���� : 13:48
//�� : 
#include <iostream>
#include <vector>
#define MAX 26

using namespace std;

// �ڽ� ��带 ������ ����ü
struct node {
	char left;
	char right;
};

// ����� ������ ������ ����
// �ִ� ������ ��� �������� �̸� ����� ���´�
vector<node> tree(MAX);


// ���� ��ȸ
void pre(char p) {
	cout << p;
	if (tree[p - 'A'].left != '.') {
		pre(tree[p - 'A'].left);
	}
	if (tree[p - 'A'].right != '.') {
		pre(tree[p - 'A'].right);
	}
}

// ���� ��ȸ
void mid(char p) {
	if (tree[p - 'A'].left != '.') {
		mid(tree[p - 'A'].left);
	}
	cout << p;
	if (tree[p - 'A'].right != '.') {
		mid(tree[p - 'A'].right);
	}
}

// ���� ��ȸ
void post(char p) {
	if (tree[p - 'A'].left != '.') {
		post(tree[p - 'A'].left);
	}
	if (tree[p - 'A'].right != '.') {
		post(tree[p - 'A'].right);
	}
	cout << p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char P, lc, rc;
		cin >> P >> lc >> rc;
		tree[P - 'A'].left = lc; //�θ� ���� ������ ġȯ�Ͽ� ó��
		tree[P - 'A'].right = rc; //�θ� ���� ������ ġȯ�Ͽ� ó��
	}

	pre('A');
	cout << '\n';
	mid('A');
	cout << '\n';
	post('A');
	cout << '\n';


	return 0;
}