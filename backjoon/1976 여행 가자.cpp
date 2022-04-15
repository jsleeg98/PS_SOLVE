//난이도 : 골드4
//시작 : 
//끝 :
#include <iostream>

using namespace std;

int parent[201]; //부모 노드를 저장

//부모 노드를 재귀적으로 찾으면서 바꿔준다.
int getParent(int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = getParent(parent[n]); //찾으면서 바꿔줘야한다. 
	}
}

//같은 부모 노드인지 확인
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

//부모 노드를 합침
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b); 
	if (!checkParent(a, b)) { //부모 노드가 다른경우
		if (a < b) { //노드 번호가 더 작은 것으로 변경
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

	//부모 노드 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	//연결 상태가 1이라면 합침
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int state;
			cin >> state;
			if (state) {
				unionParent(i, j);
			}
		}
	}

	//첫번째 들어온 노드 번호의 부모를 저장
	int tmp_node;
	cin >> tmp_node;
	int result = parent[tmp_node];
	int result_state = 1;
	//다음부터 들어오는 노드 번호의 부모를 파악하여 이전과 다르면 바로 종료
	for (int i = 2; i <= M; i++) {
		cin >> tmp_node;
		if (parent[tmp_node] != result) {
			result_state = 0;
			break;
		}
	}

	//1이면 부모 노드 번호가 다 같은 것
	if (result_state == 1) {
		cout << "YES" << '\n';
	}
	else { //0이면 부모 노드 번호가 다른게 있는 것
		cout << "NO" << '\n';
	}

	return 0;
}