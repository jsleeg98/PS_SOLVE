//난이도 : 골드4
//시작 : 
//끝 :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//부모 노드를 재귀적으로 파악한다.
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

//각 부모 노드를 합친다. 이때 작은 값을 부모 노드로 한다.
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a; //작은 값을 부모 노드로
	else parent[a] = b;
}

//같은 부모 노드를 가지는지 확인한다. 
//같은 부모 노드를 가진다면 이미 연결되어 있다는 것을 의미한다.
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1; //같은 부모 노드를 가진다면 1 반환
	else return 0; //다른 부모 노드를 가진다면 0 반환
}

//Edge 클래스 선언
class Edge {
public:
	int node[2]; //0번은 시작 노드, 1번은 끝 노드
	int distance; //가중치
	Edge(int a, int b, int distance) { //생성자 선언
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) { // sort를 위해 비교 연산자 재정의
		return this->distance < edge.distance;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Edge> v;
	int parent[10001];
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		v.push_back(Edge(A, B, C));
	}

	for (int i = 1; i <= V; i++) { //부모 노드 테이블 초기화, 자기 자신이 부모 노드가 되도록
		parent[i] = i;
	}


	sort(v.begin(), v.end()); //distance 오름차순 정렬

	int sum = 0; //거리 저장
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent, v[i].node[0], v[i].node[1])) { //부모 노드가 겹치지 않는 경우 = 사이클이 생기지 않는 경우
			sum += v[i].distance; //거리 누적합
			unionParent(parent, v[i].node[0], v[i].node[1]); //합집합
		}
	}

	cout << sum << '\n'; //거리 출력

	return 0;
}