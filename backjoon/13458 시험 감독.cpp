//난이도 : 브론즈2
//시작 : 19:52
//끝 : 20:24
#include <iostream>

using namespace std;

int A[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int B, C;
	cin >> B >> C;

	long long int cnt = 0; //감독관의 수가 int 범위를 넘어가는 경우가 있다.
	// N = 1000000
	// A가 모두 1000000이고 B, C가 1인 경우 넘어간다

	for (int i = 0; i < N; i++) {
		cnt++; // 총 감독관 1명 카운트
		if (A[i] - B > 0) {
			int tmp = (A[i] - B) / C;
			cnt += tmp;
			if ((A[i] - B) % C > 0) {
				cnt++; //나머지가 있는 경우 부감독관 한명 추가
			}
		}
	}


	cout << cnt << '\n';

	return 0;
}