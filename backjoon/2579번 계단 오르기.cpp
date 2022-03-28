//난이도 : 실버3
//시작 : 17:50
//끝 : 18:36
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int stair[301] = { 0 }; //계단 점수 저장 배열
	int DP[301] = { 0 }; //DP 저장 배열
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	
	DP[1] = stair[1]; //계단이 1개일 떄 최적 값 저장
	DP[2] = stair[1] + stair[2]; //계단이 2개 일때 최적 값 저장

	for (int i = 3; i <= N; i++) { //계단이 3개 이상일 때 최적 값 저장
		//현재 계단을 밟는다는 가정하에
		//전계단을 밟고 전전전계단을 밟는 경우와 전전계단을 밟는 경우 중 큰 값을 취하여 저장
		DP[i] = max(stair[i] + stair[i - 1] + DP[i - 3], stair[i] + DP[i-2]);
	}

	cout << DP[N] << '\n'; //현재 계단을 밟은 최적 값 출력
	


	return 0;
}