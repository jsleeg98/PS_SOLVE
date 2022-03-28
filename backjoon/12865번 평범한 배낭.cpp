//난이도 : 골드5
//시작 : 12:08 - 13:00
//끝 : 14:54 - 15:30
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//배열의 크기가 크기 때문에 전역변수로 선언
int DP[100001][101] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w[101] = { 0 }; //무게 저장 배열
	int v[101] = { 0 }; //가치 저장 배열

	int N, K; 
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}

	//i는 가방의 무게 제한, j는 물건 번호
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (i >= w[j]) { // 해당 물건을 담을 수 있는 경우
				//물건을 담고 남은 무게로 가질 수 있는 최적 가치와 물건을 담지 않은 경우를 비교하여
				//높은 가치를 저장
				DP[i][j] = max(v[j] + DP[i - w[j]][j - 1], DP[i][j - 1]);
			}
			else { //물건을 담을 수 없는 경우 이전 물건 까지의 최대 가치를 저장
				DP[i][j] = DP[i][j - 1];
			}
		}
	}

	//가방 무게에 대한 모든 물건을 봤을 때의 최대 가치 출력
	cout << DP[K][N] << '\n';

	return 0;
}