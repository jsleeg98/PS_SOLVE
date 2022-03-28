//난이도 : 실버1
//시작 : 18:09
//끝 :
#include <iostream>

using namespace std;

int sticker[3][100001] = { 0 }; //스티커 점수 저장 배열
int DP[3][100001] = { 0 }; //각 행당 스티커 점수 DP 저장 배열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		for (int j = 1; j <= 2; j++) {
			for (int k = 1; k <= N; k++) {
				cin >> sticker[j][k];
			}
		}
		//DP에서 1행과 2행이 있는데 이곳에는 각 행에 대해서 최대 값을 저장하는 배열이다.
		//총 3가지 경우 중 최대값을 저장한다.
		//1. 현재 위치 스티커를 선택하고 이전 위치의 다른 행의 스티커를 고른 경우
		//2. 현재 위치 스티커를 선택하지 않고 이전 위치의 같은 행의 스티커를 고른 경우
		//3. 현재 위치 스티커를 선택하지 않고 이전 위치의 다른 행의 스티커를 고른 경우
		//이는 현재 위치 스티커를 고를 경우 이전 스티커는 고정되고
		//현재 위치 스티커를 고르지 않으면 이전에 어떤 행의 스티커를 골라도 상관 없다는 규칙에 의해 세울 수 있다.
		DP[1][1] = sticker[1][1]; //첫번째는 이전이 없기 때문에 스티커를 고른 경우가 최대가 된다.
		DP[2][1] = sticker[2][1]; //첫번째는 이전이 없기 때문에 스티커를 고른 경우가 최대가 된다.
		for (int j = 2; j <= N; j++) { //각각의 행에 대해서 DP 실시
			DP[1][j] = max(sticker[1][j] + DP[2][j - 1], max(DP[1][j - 1], DP[2][j - 1]));
			DP[2][j] = max(sticker[2][j] + DP[1][j - 1], max(DP[1][j - 1], DP[2][j - 1]));
		}
		/*for (int k = 1; k <= 2; k++) {
			for (int j = 1; j <= N; j++) {
				cout << sticker[k][j] << " ";
			}
			cout << '\n';
		}
		for (int k = 1; k <= 2; k++) {
			for (int j = 1; j <= N; j++) {
				cout << DP[k][j] << " ";
			}
			cout << '\n';
		}
		*/
		//두 행 중 최대 값을 선택하여 출력
		cout << max(DP[1][N], DP[2][N]) << '\n';
	}

	return 0;
}