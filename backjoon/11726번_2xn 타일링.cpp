//시작 : 11:04
//끝: 11:17

#include <iostream>

using namespace std;

int dp[1001] = {0};

int dp_solve(int n) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		//10007로 나누어서 결과를 저장하지 않으면 int를 넘어가서 제대로된 계산 불가능
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; 
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << dp_solve(n) << '\n';
	return 0;
}