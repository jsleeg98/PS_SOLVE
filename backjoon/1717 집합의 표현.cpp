//난이도 : 골드4
//시작 : 22:14
//끝 : 22:28
#include <iostream>

using namespace std;

int parent[1000001] = { 0 };

//부모 노드를 알아내는 함수
int getParent(int node) {
	if (parent[node] == node) { //자기 자신이 부모인 경우 자기 자신 리턴
		return node;
	}
	return parent[node] = getParent(parent[node]); //자기 자신이 부모가 아닌 경우 재귀적으로 부모 찾음
}

//부모 노드를 합치는 코드
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) { //작은 노드 번호로 합친다.
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

//같은 집합인지 확인하는 코드 
//부모가 같으면 같은 집합
int checkParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) { //부모 노드가 같은 경우
		return 1;
	}
	else { //부모 노드가 다른 경우
		return 0;
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { //자기 자신을 부모 노드로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 0) {
			if (!checkParent(a, b)) { //같은 부모가 아닌 경우
				unionParent(a, b); //합침
			}
			
		}
		else if (mode == 1) {
			if (checkParent(a, b)) { //같은 부모인 경우
				cout << "YES" << '\n'; //YES 출력
			}
			else {//다른 부모인 경우
				cout << "NO" << '\n'; //NO 출력
			}
		}
	}


	return 0;
}