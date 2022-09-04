//난이도 : 실버 2
//시작 : 19:17
//끝 : 21:03
#include <iostream>
#include <vector>

using namespace std;


int parent[100001] = { 0 };  // 모든 부모 노드 번호를 0으로 초기화
vector<int> children[100001];  // 자식 노드들을 저장하는 벡터 배열

//  부모 노드를 재귀적으로 설정하는 함수
void set_parent(int node) {
	for (int i = 0; i < children[node].size(); i++) {
		if(parent[children[node][i]] == 0){  // 부모 노드가 정해지지 않은 경우
			parent[children[node][i]] = node;  // 부모 노드 설정
			set_parent(children[node][i]);  // 재귀적으로 자식 노드에 부모 노드 설정
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	parent[1] = 1;  // 1번 노드는 루트 노드로 설정

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b; 
		cin >> a >> b;
		if (parent[a] != 0) {  // a의 부모 노드가 이미 설정된 경우
			parent[b] = a;
			if (children[b].size() > 0) {
				set_parent(b);
			}
		}
		else if (parent[b] != 0) {  // b의 부모 노드가 이미 설정된 경우
			parent[a] = b;
			if (children[a].size() > 0) {
				set_parent(a);
			}
		}
		else {  // a, b 둘다 부모 노드가 이미 설정되어 있지 않은 경우
			children[a].push_back(b);  // 자식 노드로 우선 설정
			children[b].push_back(a);  // 자식 노드로 우선 설정
		}
	}

	// 결과 출력
	for (int i = 2; i < N + 1; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}