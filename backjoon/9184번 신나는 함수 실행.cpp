//난이도 : 실버2
//시작 : 17:03
//끝 : 17:34
#include <iostream>

using namespace std;

int dp[101][101][101] = { 0 }; //부분 정답 저장 배열

int w(int a, int b, int c) {
	if (dp[a][b][c] != 0) { //이미 부분 정답이 있다면 바로 부분 정답 리턴
		return dp[a][b][c];
	}
	if (a <= 50 || b <= 50 || c <= 50) { //0부터 100까지를 -50에서 50으로 사용하기 때문에 +50을 하였다.
		
		return dp[a][b][c] = 1; //부분 정답 저장 배열에 저장하면서 리턴
	}
	if (a > 70 || b > 70 || c > 70) { //0부터 100까지를 -50에서 50으로 사용하기 때문에 +50을 하였다.
		return dp[a][b][c] = w(70, 70, 70); //부분 정답 저장 배열에 저장하면서 리턴
	}
	if (a < b && b < c) {
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); //부분 정답 저장 배열에 저장하면서 리턴 
	}
	return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1); //부분 정답 저장 배열에 저장하면서 리턴
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		else {
			cout << "w(" << a << ", " << b << ", " << c << ") = ";
			
			cout << w(a + 50, b + 50, c + 50) << '\n';
		}
	}

	return 0;
}