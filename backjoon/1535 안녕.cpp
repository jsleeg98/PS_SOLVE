//난이도 : 실버2
//시작 : 09:29
//끝 :
#include <iostream>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W[21] = { 0 };
	int V[21] = { 0 };
	int DP[100][21] = { 0 };
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> W[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}

	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= N; j++) {
			if (i >= W[j]) {
				DP[i][j] = max(V[j] + DP[i - W[j]][j - 1], DP[i][j - 1]);
			}
			else {
				DP[i][j] = DP[i][j - 1];
			}
		}
	}

	cout << DP[99][N] << '\n';

	return 0;
}