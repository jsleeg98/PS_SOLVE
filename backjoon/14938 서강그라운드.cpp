//���̵� : ���4
//���� : 11:06
//�� :
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> a[101]; //��庰 ���Ḯ��Ʈ ����
int INF = 987654321; //���� ����


int* dijkstra(int d[], int start) { //�Է����� �ִ� �Ÿ� ���� �迭�� ���۳�� ����
	d[start] = 0; //���� ��� �Ÿ� 0
	priority_queue<pair<int, int>> pq; //�켱���� ť ���
	pq.push(make_pair(start, 0));

	while (!pq.empty()) { //�켱 ���� ť�� �� �� ���� �ݺ�
		int current = pq.top().first; //���� ���
		int distance = pq.top().second; //���� ��� �Ÿ�
		pq.pop();
		if (d[current] < distance) continue; //�ִ� �Ÿ� �迭�� ���� ���� �Ÿ����� ������ �ٷ� �н�
		for (int i = 0; i < a[current].size(); i++) { //����Ǿ� �ִ� ��� ���� ��忡 ���ؼ�
			int next = a[current][i].first; //���� ��� ��ȣ
			int nextDistance = a[current][i].second + distance; //���� ���� ��� �Ÿ�
			if (nextDistance < d[next]) { //���İ��� ��찡 ���� �ִ� �Ÿ����� �������
				d[next] = nextDistance; //�ִ� �Ÿ� �迭 ������Ʈ
				pq.push(make_pair(next, nextDistance)); //���� ������ ���� �켱���� ť�� push
			}
		}
	}
	//for (int i = 1; i <= 5; i++) {
	//	cout << d[i] << " ";
	//}
	//cout << '\n';
	return d; //�ִ� �Ÿ� �迭 ��ȯ

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r;//��������, ��������, ���� ����
	cin >> n >> m >> r;

	//������ ���� �Է�
	int item[101] = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	//�� �Է�
	for (int i = 0; i < r; i++) {
		int start;
		int end;
		int distance;
		cin >> start >> end >> distance;
		a[start].push_back(make_pair(end, distance));
		a[end].push_back(make_pair(start, distance));
	}

	int max_item = 0; //�ִ� ������ ���� ����
	for (int i = 1; i <= n; i++) {
		int d[101] = { 0 }; //�ִ� �Ÿ� �迭
		for (int i = 1; i <= n; i++) { //�Ÿ��� ��� �������� �ʱ�ȭ
			d[i] = INF;
		}
		int* tmp_d = dijkstra(d, i); //��� �������κ��� ���ͽ�Ʈ�� �˰��� ��� �� �迭�� �޴´�.
		int tmp_item = 0; //���� ��ġ���� ���� �� �ִ� ������ ���� ���� 
		/*for (int j = 1; j <= n; j++) {
			cout << tmp_d[j] << " ";
		}
		cout << '\n';*/
		for (int j = 1; j <= n; j++) { //���� ���� ���� ���� �ִ� �����۸� �����Ͽ� ����
			if (tmp_d[j] <= m) {
				tmp_item += item[j];
			}
		}
		//cout << i << " " << tmp_item << '\n';
		if (max_item < tmp_item) { //���������� �ִ� ������ ������ ����
			max_item = tmp_item;
		}
	}

	cout << max_item << '\n';

	return 0;
}