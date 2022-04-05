//���̵� : ���4
//���� : 
//�� :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�θ� ��带 ��������� �ľ��Ѵ�.
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

//�� �θ� ��带 ��ģ��. �̶� ���� ���� �θ� ���� �Ѵ�.
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a; //���� ���� �θ� ����
	else parent[a] = b;
}

//���� �θ� ��带 �������� Ȯ���Ѵ�. 
//���� �θ� ��带 �����ٸ� �̹� ����Ǿ� �ִٴ� ���� �ǹ��Ѵ�.
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1; //���� �θ� ��带 �����ٸ� 1 ��ȯ
	else return 0; //�ٸ� �θ� ��带 �����ٸ� 0 ��ȯ
}

//Edge Ŭ���� ����
class Edge {
public:
	int node[2]; //0���� ���� ���, 1���� �� ���
	int distance; //����ġ
	Edge(int a, int b, int distance) { //������ ����
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) { // sort�� ���� �� ������ ������
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

	for (int i = 1; i <= V; i++) { //�θ� ��� ���̺� �ʱ�ȭ, �ڱ� �ڽ��� �θ� ��尡 �ǵ���
		parent[i] = i;
	}


	sort(v.begin(), v.end()); //distance �������� ����

	int sum = 0; //�Ÿ� ����
	for (int i = 0; i < v.size(); i++) {
		if (!findParent(parent, v[i].node[0], v[i].node[1])) { //�θ� ��尡 ��ġ�� �ʴ� ��� = ����Ŭ�� ������ �ʴ� ���
			sum += v[i].distance; //�Ÿ� ������
			unionParent(parent, v[i].node[0], v[i].node[1]); //������
		}
	}

	cout << sum << '\n'; //�Ÿ� ���

	return 0;
}