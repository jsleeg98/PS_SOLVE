//���̵� : �ǹ� 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<int> prices;  // �ְ� �迭
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			prices.push_back(tmp);
		}
		reverse(prices.begin(), prices.end());  // �迭 ������
		int sell_price = prices[0]; // �ŵ��� �ʱ�ȭ
		long long result = 0;
		for (int j = 1; j < N; j++) {
			if (sell_price > prices[j]) {  // �ŵ������� �ְ��� ���� ��� ���� �߰�
				result += sell_price - prices[j];
			}
			else {  // �׷��� ���� ��� �ŵ��� ����
				sell_price = prices[j];
			}
		}
		cout << result << '\n';

	}



	return 0;
}