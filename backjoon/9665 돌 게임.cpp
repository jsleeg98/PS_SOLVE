//난이도 : 실버5
//시작 : 19:40
//끝 :
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> DP(1001);
	int N;
	cin >> N;
	//if (N % 2 == 0) {
	//	cout << "CY" << '\n';
	//}
	//else {
	//	cout << "SK" << '\n';
	//}
	DP[1] = 0;
	DP[2] = 1;
	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 2];
	}
	
	if (DP[N] == 0) {
		cout << "SK" << '\n';
	}
	else {
		cout << "CY" << '\n';
	}

	return 0;
}