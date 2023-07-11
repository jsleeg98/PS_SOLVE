//난이도 : 실버 2

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
		vector<int> prices;  // 주가 배열
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			prices.push_back(tmp);
		}
		reverse(prices.begin(), prices.end());  // 배열 뒤집기
		int sell_price = prices[0]; // 매도가 초기화
		long long result = 0;
		for (int j = 1; j < N; j++) {
			if (sell_price > prices[j]) {  // 매도가보다 주가가 낮은 경우 이익 추가
				result += sell_price - prices[j];
			}
			else {  // 그렇지 않은 경우 매도가 갱신
				sell_price = prices[j];
			}
		}
		cout << result << '\n';

	}



	return 0;
}