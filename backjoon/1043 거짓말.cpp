//난이도 : 골드4
//시작 : 11:38
//끝 : 12:09
#include <iostream>
#include <vector>

using namespace std;

int parent[51]; //부모 노드 저장

//부모 노드 얻기(재귀적)
int getParent(int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = getParent(parent[n]);
	}
}

//같은 부모인지 확인
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

//노드 번호가 작은 것으로 부모 합치기
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (!checkParent(a, b)) {
		if (a < b) {
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

	vector<int> v[50]; //파티 참여자 저장 벡터
	int know[51] = { 0 }; //거짓말을 아는 사람 번호
	int N, M;
	cin >> N >> M;
	int T; //거짓말을 아는 사람 수
	cin >> T;
	//거짓말을 아는 사람 입력
	for (int i = 0; i < T; i++) {
		cin >> know[i];
	}
	//파티 참여자 입력
	for (int i = 0; i < M; i++) {
		int people_num; //파티 참여자 수
		cin >> people_num;
		for (int j = 0; j < people_num; j++) {
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp); //벡터에 push
		}
	}

	//for (int i = 0; i < M; i++) {
	//	for (int j = 0; j < v[i].size(); j++) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	//부모 노드 자기 자신으로 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	//동일 파티 참여자들을 하나의 집합으로 합치기
	for (int i = 0; i < M; i++) {
		if (v[i].size() == 1) { //참여자가 한명이면 패스
			continue;
		}
		else { //참여자가 2명 이상이면
			int num = v[i][0]; //처음에 나오는 번호가 가장 작은 번호라고 가정하고
			for (int j = 1; j < v[i].size(); j++) {//나머지 파티 참여자 합침
				unionParent(num, v[i][j]);
			}
		}
	}

	//여기까지 수행하면 parent 배열에는 같은 파티 참여자이고 한명이라도 겹치는 사람이 있으면 모두 같은 파티 참여자로 처리하여
	//합쳐져 있다.

	//거짓말 할 수 있는 파티 개수 세기
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool fail = false;
		int p = getParent(v[i][0]); //각 파티의 맨 번호만 확인하면 된다. 그 이유는 이미 하나의 집합으로 처리해 두었고 맨앞이 가장 작은 번호이기 때문이다.
		for (int j = 0; j < T; j++) {
			//여기서 getParent(know[j])를 하지 않고 know[j]만을 한다면 예제 7번과 같이 거짓말을 아는 사람의 노드 번호가 가장 작지 않은 경우에 탐지가 불가능하다!!!!!
			if (getParent(know[j]) == p) { //거짓말을 아는 사람의 부모 노드를 찾아 그 노드와 파티 참여자 부모 노드를 비교해서 같다면
				fail = true; //거짓말을 할 수 없음 처리
				break;
			}
		}
		if (!fail) { //거짓말을 할 수 있는 경우에만 +1
			cnt++;
		}
	}

	//거짓말 할 수 있는 파티 수 출력
	cout << cnt << '\n';

	return 0;
}