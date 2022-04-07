//난이도 : 골드4
//시작 : 09:26
//끝 : 09:46
#include <iostream>
#include <limits>

using namespace std;

#define INF 100000000 //무한 값 정의

int dp[101][101] = { 0 };

//n은 정점의 개수
void floyd_warshall(int n) {
	// k : 거처가는 정점
	for (int k = 1; k <= n; k++) {
		// i : 시작 정점
		for (int i = 1; i <= n; i++) {
			// j : 도착 정점
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] + dp[k][j] < dp[i][j]) { //k를 거처가는 것이 비용이 덜 든다면 값 갱신
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//모든 경로를 무한으로 초기화
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dp[i][j] = INF;
		}
	}

	int n, m;
	cin >> n >> m;

	//자기 자신을 시작, 도착으로 가지면 거리는 0이다.
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dp[a][b] > c) { // 최소 거리만 갱신 //같은 구간을 연결하는 노선이 하나가 아닐 수 있기 때문
			dp[a][b] = c;
		}
	}

	// 플로이드-마샬 알고리즘 수행
	floyd_warshall(n);

	//결과 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == INF) { //여전히 갈 수 없는 경우
				dp[i][j] = 0; //0으로 출력
				cout << dp[i][j] << " ";
			}
			else {
				cout << dp[i][j] << " ";
			}
		}
		cout << '\n';
	}


	return 0;
}