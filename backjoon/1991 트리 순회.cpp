//난이도 : 실버1
//시작 : 13:48
//끝 : 
#include <iostream>
#include <vector>
#define MAX 26

using namespace std;

// 자식 노드를 저장할 구조체
struct node {
	char left;
	char right;
};

// 노드의 정보를 저장할 벡터
// 최대 저장할 노드 개수까지 미리 만들어 놓는다
vector<node> tree(MAX);


// 전위 순회
void pre(char p) {
	cout << p;
	if (tree[p - 'A'].left != '.') {
		pre(tree[p - 'A'].left);
	}
	if (tree[p - 'A'].right != '.') {
		pre(tree[p - 'A'].right);
	}
}

// 중위 순회
void mid(char p) {
	if (tree[p - 'A'].left != '.') {
		mid(tree[p - 'A'].left);
	}
	cout << p;
	if (tree[p - 'A'].right != '.') {
		mid(tree[p - 'A'].right);
	}
}

// 후위 순회
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
		tree[P - 'A'].left = lc; //부모 노드는 정수로 치환하여 처리
		tree[P - 'A'].right = rc; //부모 노드는 정수로 치환하여 처리
	}

	pre('A');
	cout << '\n';
	mid('A');
	cout << '\n';
	post('A');
	cout << '\n';


	return 0;
}