//���̵� : ��� 3

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct lecture{
	int d;
	int p;
};

// p�� ���� ������ �����ϰ� ���ٸ� d�� ���� ������ ����
struct compare_1 {
	bool operator()(const lecture& a, const lecture& b) {
		if (a.p == b.p) {
			return a.d > b.d;
		}
		else {
			return a.p > b.p;
		}
	}
};

// d�� ���� ������ �����ϰ� ���ٸ� p�� ū ������ ����
struct compare_2 {
	bool operator()(const lecture& a, const lecture& b) {
		if (a.d == b.d) {
			return a.p < b.p;
		}
		else {
			return a.d > b.d;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<lecture, vector<lecture>, compare_2> pq;
	priority_queue<lecture, vector<lecture>, compare_1> pq_result;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		lecture tmp;
		cin >> tmp.p >> tmp.d;
		pq.push(tmp);
	}

	//while (!pq.empty()) {
	//	cout << pq.top().d << " " << pq.top().p << '\n';
	//	pq.pop();
	//}

	int day = 0;
	while (!pq.empty()) {  
		if (day < pq.top().d) { // �ش� ��¥�� ������ �� �� �ִ� ���
			lecture tmp = pq.top();
			pq_result.push(tmp);  //���� ť�� �߰�
			pq.pop();
			day += 1;  // ��¥ +1
		}
		else {  // �ش� ��¥�� ������ �� �� ���� ���
			if (pq_result.top().p < pq.top().p) {  // ���� ������ ���� �ʰ� ���� ������ �ϴ� ���� �� ������ ���
				pq_result.pop();  
				pq_result.push(pq.top());  // ���� ť ������Ʈ -> ���� ������ ����
				pq.pop();
			}
			else {  // ���� ������ �ϴ°� ������ ��� 
				pq.pop();
			}
		}
	}

	// ���� ť�� ���� ��
	int total = 0;
	while (!pq_result.empty()) {
		total += pq_result.top().p;
		pq_result.pop();
	}

	cout << total << '\n';

	return 0;
}