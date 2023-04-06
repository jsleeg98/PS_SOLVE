//난이도 : 골드2
//시작 : 19:15
//끝 :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, K;
		cin >> N >> K;
		vector<int> arr;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}
		vector<int> LIS;
		LIS.push_back(arr[0]);  // 가장 첫번째 값 바로 LIS 배열에 넣기
		for (int i = 1; i < N; i++) {
			if (LIS[LIS.size() - 1] < arr[i]) {  // LIS 배열의 끝 값보다 넣으려는 값이 큰 경우
				LIS.push_back(arr[i]);  // LIS 배열 끝에 추가
			}
			else {  // 그렇지 않은 경우
				int pos = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();  // LIS 배열에서 넣으려는 값 이상의 값을 가지는 가장 첫번째 인덱스
				LIS[pos] = arr[i];  // 그 위치에 넣으려는 값을 대치한다. -> 맨 끝의 값이 바뀌는 경우 LIS 맨 끝의 값을 최대한 작게 유지해주며 이는 LIS를 만들 수 있는 조건이다.
			}
		}
		cout << "Case #" << t + 1 << '\n';
		if (LIS.size() >= K) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}