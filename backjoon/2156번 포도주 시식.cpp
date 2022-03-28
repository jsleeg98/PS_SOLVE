//난이도 : 실버1
//시작 : 23:20
//끝 : 23:41
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[10001] = { 0 }; //포도주 양 저장 배열
	int DP[10000] = { 0 }; //DP 배열
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	DP[1] = A[1]; //DP 초기화 - 1잔이 있을 때는 다 마시는게 최대
	DP[2] = A[1] + A[2]; //DP 초기화 - 2잔이 있을 때도 다 마시는게 최대
	for (int i = 3; i <= N; i++) { //3잔부터 DP
		//최대값 - 현재 잔을 마시고 전 잔을 마시고 전전전 잔에 대한 DP vs 현재 잔을 마시고 전전 잔에 대한 DP vs 현재 잔을 안마시고 전 잔에 대한 DP
		DP[i] = max(A[i] + A[i - 1] + DP[i - 3], max(A[i] + DP[i - 2], DP[i - 1]));
	}

	//최대 값 출력
	cout << DP[N] << '\n';

	return 0;
}