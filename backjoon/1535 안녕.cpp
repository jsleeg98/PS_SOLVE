//난이도 : 실버2
//시작 : 09:29
//끝 : 10:03
#include <iostream>


using namespace std;

//배낭 문제로 해석하여 체력을 물건의 무게, 기쁨을 물건의 가치로 해석하였다.
//세준이의 체력이 100이기 때문에 체력 99까지의 DP를 구해 최적의 값을 출력한다.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W[21] = { 0 }; //물건의 무게를 저장할 배열
	int V[21] = { 0 }; //물건의 가치를 저장할 배열
	int DP[100][21] = { 0 }; //배낭의 무게별 최적 값을 저장할 DP
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> W[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}

	for (int i = 1; i <= 99; i++) { //배낭의 무게를 1부터 99까지 늘린다.
		for (int j = 1; j <= N; j++) { //물건을 앞에서부터 순회
			if (i >= W[j]) { //물건을 담을 수 있는 경우
				//물건을 담는 경우와 담지 않는 경우 중 최대 값을 저장
				DP[i][j] = max(V[j] + DP[i - W[j]][j - 1], DP[i][j - 1]);
			}
			else { //물건을 담을 수 없는 경우
				DP[i][j] = DP[i][j - 1]; //물건을 담지 않는 경우를 저장
			}
		}
	}
	// 배낭의 무게가 99일때 최적 값을 출력한다.
	cout << DP[99][N] << '\n';

	return 0;
}