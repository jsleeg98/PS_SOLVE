//난이도 : 골드5
//시작 : 11:00
//끝 : 11:57
#include <iostream>

using namespace std;

// 부분 LCS를 저장하기위한 DP
int LCS_DP[1001][1001] = { 0 };

//LCS는 Long Common Sequence로 가장 긴 공통 부분이다. 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//문자열은 인덱스 1부터 들어갈 수 있도록 맨 앞은 빈칸으로 채워준다.
	string a = " "; 
	string b = " ";
	
	string tmp;
	cin >> tmp;
	a += tmp;
	cin >> tmp;
	b += tmp;

	//2차원 배열로 LCS_DP를 만들어 저장하며
	//문자가 일치할 경우 왼쪽 위 대각선 값에서 +1 한 값,
	//문자가 불일치할 경우 위, 오른쪽 값 중 큰 값을 취해 저장한다.
	for (int i = 1; i < b.length(); i++) {
		for (int j = 1; j < a.length(); j++) {
			if (b[i] == a[j]) {
				LCS_DP[i][j] = LCS_DP[i - 1][j - 1] + 1;
			}
			else {
				LCS_DP[i][j] = max(LCS_DP[i - 1][j], LCS_DP[i][j - 1]);
			}
		}
	}

	//LCS_DP 가장 오른쪽 아래에 있는 값이 LCS 값이다.
	cout << LCS_DP[b.length() - 1][a.length() - 1] << '\n';

	return 0;
}