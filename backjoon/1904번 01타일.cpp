//Ω√¿€ : 10:35
//≥° : 10:44
#include <iostream>
#include <vector>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> dp(1000000, 0);
	dp[1] = 1;
	dp[2] = 2;
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[N] << '\n';

	return 0;
}