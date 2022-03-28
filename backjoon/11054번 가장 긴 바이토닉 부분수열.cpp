//난이도 : 골드 3
//시작 : 20:00
//끝 : 20:49
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int A[1001] = {0};
	int DP_up[1001] = {0};
	int DP_down[1001] = {0};
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	//왼쪽부터 커질 수 있는 최대 수열 길이를 DP_up에 저장
	for (int i = 1; i <= N; i++) {
		int maxn = DP_up[i];
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) {
				if (DP_up[j] > maxn) {
					maxn = DP_up[j];
				}
			}
		}
		DP_up[i] = maxn + 1; //1 더해서 자기 자신 포함하여 저장
	}

	//오른쪽부터 커질 수 있는 최대 수열 길이를 DP_down에 수열 길이 저장
	for (int i = N; i >= 1; i--) {
		int maxn = DP_down[i];
		for (int j = i; j <= N; j++) {
			if (A[i] > A[j]) {
				if (DP_down[j] > maxn) {
					maxn = DP_down[j];
				}
			}
		}
		DP_down[i] = maxn + 1; //1 더해서 자기 자신 포함하여 수열 길이 저장
	}

	//i 위치를 기준으로 바이토닉 수열 만들었을 떄 길이를 계산하고 최대 값 찾기
	int result = DP_up[1] + DP_down[1] - 1;
	for (int i = 1; i <= N; i++) {
		if (result < DP_up[i] + DP_down[i] - 1) {
			result = DP_up[i] + DP_down[i] - 1;
		}
	}


	/*for (int i = 1; i <= N; i++) {
		cout << DP_up[i] << " ";
	}
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		cout << DP_down[i] << " ";
	}
	cout << '\n';*/

	//최대값 출력
	cout << result << '\n';

	return 0;
}