//���̵� : ���4

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//// �������� �켱���� ť
	//priority_queue<int, vector<int>, greater<int>> pq;  
	//int N;
	//cin >> N;
	//for (int i = 0; i < N; i++) {
	//	int tmp;
	//	cin >> tmp;
	//	pq.push(tmp);
	//}
	//
	//// ���� �� ���� ���� �� Ƚ���� ���ذ��� ��
	//// �̷��� ���� ī�� ������ �ٽ� �迭�� �ְ� �������� ����
	//// �迭�� ������ �ٷ� ������ ���ִ� ���� �켱���� ť

	//int result = 0;  // �� Ƚ��
	//while (pq.size() > 1) {  // size�� 2�� �̻��� ��
	//	int a = pq.top();  // ���� ���� ����
	//	pq.pop();
	//	int b = pq.top();  // �� ���� ���� ����
	//	pq.pop();
	//	pq.push(a + b);  // ���� �������� �켱���� ť�� �ֱ�
	//	result += a + b;  // �� Ƚ�� �߰�
	//}

	//cout << result << '\n';

	int N;
	cin >> N;

	vector<int> card;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		card.push_back(tmp);
	}

	sort(card.begin(), card.end(), greater<int>());
	//reverse(card.begin(), card.end());
	int result = 0;
	while (card.size() > 1) {
		int a = card.back();
		card.pop_back();
		int b = card.back();
		card.pop_back();
		result += a + b;
		card.push_back(a + b);
		sort(card.begin(), card.end(), greater<int>());
	}

	cout << result << '\n';
	

	return 0;
}