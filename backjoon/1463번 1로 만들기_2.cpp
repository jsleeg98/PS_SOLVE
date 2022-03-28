//난이도 : 실버3
//시작 : 20:46
//끝 : 20:51
#include <iostream>

using namespace std;

int DP[1000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int X;
	cin >> X;

	//DP에는 해당 번호가 되기 위한 최소 횟수
	DP[1] = 0; //1은 0번만에 가능
	for (int i = 2; i <= X; i++) {
		DP[i] = DP[i - 1] + 1; //우선 전에서 +1 한 경우로 DP값 갱신
		if (i % 2 == 0) { //2로 나누어 진다면 2로 나누는 경우와 원래 전에서 +1 한 경우 중 최소값으로 DP 값 갱신
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
		if (i % 3 == 0) { //3으로 나우어 진다면 3으로 나누는 경우와 원래 전에서 +1 한 경우 중 최소 값으로 DP 값 갱신
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
	}

	//결과 출력
	cout << DP[X] << '\n';


	return 0;
}