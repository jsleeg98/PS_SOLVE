//난이도 : 실버2
//시작 : 23:50
//끝 : 00:24
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[1001] = { 0 };
	int DP[1001] = { 0 };
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	DP[1] = 1;
	for (int i = 2; i <= N; i++) { //자신을 포함하는 경우 가장 긴 증가 수열 길이를 DP에 저장
		int tmp_dp = 0; //자신 보다 작은 수에서 가장 긴 수열의 길이 저장
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) { //자신 보다 작은 경우
				if (tmp_dp < DP[j]) { //현재 최대 길이보다 더 긴 경우
					tmp_dp = DP[j];
				}
			}
		}
		DP[i] = tmp_dp + 1; //자기 자신을 포함해야 하므로 +1
	}

	//DP내에서 최대 값이 가장 긴 증가 수열이다. 그 이유는 각각의 수를 포함 했을 떄 가장 긴 수열을 DP에 저장했기 때문이다.
	int maxn = DP[0];
	for (int i = 1; i <= N; i++) {
		if (maxn < DP[i]) {
			maxn = DP[i];
		}
	}


	cout << maxn << '\n';

	return 0;
}