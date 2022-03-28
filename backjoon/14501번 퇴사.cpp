//시작 : 20:50
//끝 : 21:06
#include <iostream>
#include <vector>
#include <algorithm> //max

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T[16]; //걸리는 일수
	int P[16]; //이익
	int DP[17] = { 0 }; //DP 배열 현재 일을 기준으로 가장 최적의 값
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i + 1] >> P[i + 1]; //일과 인덱스를 같게 맞춰줌
	}

	for (int i = N; i >= 1; i--) {
		//퇴사일보다 일이 늦게 끝나 일을 할 수 없는경우
		if (i + T[i] > N + 1) { 
			//오늘 일을 무조건 못하기 때문에 오늘 일을 쉰다.
			DP[i] = DP[i + 1]; 
		}
		else { //오늘 일을 할 수 있는 경우
			//일을 하지 않는 경우와 일을 하는 경우를 비교해 최대 값을 취한다.
			DP[i] = max(DP[i + 1], P[i] + DP[i + T[i]]);
		}
	}

	//첫날에 가장 최적의 값이 저장되어 이를 출력
	cout << DP[1] << '\n'; 

	return 0;
}
