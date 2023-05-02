//난이도 : 실버4
//시작 : 20:12
//끝 : 20:30
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> DP;
	//5킬로그램까지 최선의 봉지의 수 초기화
	DP.push_back(-1);  //index 0
	DP.push_back(-1);  //index 1
	DP.push_back(-1);  //index 2
	DP.push_back(1);  //index 3
	DP.push_back(-1);  //index 4
	DP.push_back(1);  //index 5
	
	int N;
	cin >> N;
	for (int i = 6; i <= N; i++) {
		int A = DP[i - 3]; // 3킬로그램 봉지로 담을 수 있는 경우의 최선의 봉지 개수
		int B = DP[i - 5]; // 5킬로그램 봉지로 담을 수 있는 경우의 최선의 봉지 개수
		if (A == -1 && B == -1) {  // 둘 다 담을 수 없는 경우
			DP.push_back(-1); 
		}
		else if (A == -1 && B != -1) {  // 5킬로그램 봉지로 담을 수 있는 경우 이전 최선의 봉지 수 +1
			DP.push_back(B + 1);
		}
		else if (A != -1 && B == -1) {  // 3킬로그램 봉지로 담을 수 있는 경우 이전 최선의 봉지 수 +1
			DP.push_back(A + 1);
		}
		else {
			DP.push_back(min(A + 1, B + 1));  // 둘 다 담을 수 있는 경우 이전 최선의 봉지 수 중 적은 봉지 수 +1
		}
	}
	cout << DP[N] << '\n';

	return 0;
}