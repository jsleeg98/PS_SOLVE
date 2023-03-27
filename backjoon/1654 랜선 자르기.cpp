//난이도 : 실버 2
//시작 : 18:50
//끝 :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;  // 필요한 랜선의 개수
	int K;  // 랜선의 개수

	vector<long long> lan;  // 가지고 있는 랜선 배열

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		lan.push_back(tmp);
	}

	sort(lan.begin(), lan.end());  // 가지고 있는 랜선 오름차순 정렬

	long long L = 1;  // Left는 0으로 초기화
	long long R = lan[lan.size() - 1];  // Right는 가지고 있는 랜선 중 가장 긴 것으로 초기화 -> 짧은 것으로 하면 1이 만약 있으면 정답을 찾지 못함
	long long result = 0;

	while (L <= R) {
		//cout << L << "---" << R << '\n';
		long long mid = (L + R) / 2;
		int cnt = 0;
		for (int i = 0; i < lan.size(); i++) {
			cnt += lan[i] / mid;
		}
		if (cnt < N) {
			R = mid - 1;
		}
		else if (cnt >= N) {
			L = mid + 1;
			if (mid > result) {
				result = mid;
			}
		}
		//cout << tmp_result << '\n';
	}

	cout << result << '\n';
  	return 0;
}