//난이도 : 실버3
//시작 : 17:25
//끝 : 17:35
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//피보나치 수열 저장 배열
	//90이 되면 int의 범위를 넘어가기 때문에 long long int 사용
	long long int DP[91];
	int N;
	cin >> N;
	DP[1] = 1; //길이가 1인 경우는 1 밖에 없다
	DP[2] = 1; //길이가 2인 경우는 10 밖에 없다
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[N] << '\n';

	return 0;
}