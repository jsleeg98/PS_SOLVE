//시작 : 11:47
//끝 : 12:00
#include <iostream>

using namespace std;

long long int dp[101] = { 0 }; //int형을 넘는 숫자가 저장될 수 있어 long long int로 선언해야 해결 가능



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	dp[8] = 5;
	
	for (int i = 9; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << dp[N] << '\n';
	}



	return 0;
}