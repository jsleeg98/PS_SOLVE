//난이도 : 골드2
//시작 : 15:45
//끝 : 해설 참고
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A[1001] = { 0 };
	int B[1001] = { 0 };
	int C[1001] = { 0 };

	vector<int> D;
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		C[i] = B[i] - A[i];
	}

	//맨 앞 설정
	int prev = C[0];
	int cnt = 0;

	if (N == 1) {
		cnt = abs(prev);
	}
	else {
		for (int i = 1; i < N; i++) {
			if (C[i] >= 0) {//양수인 경우
				if (prev < 0){ //이전이 음수인경우 - 부호 다름
					cnt += abs(prev); //이전 수행 횟수 더함
					prev = C[i]; //이전을 갱신
				}
				else if (prev < C[i]) { //양수로 오름차순인 경우
					prev = C[i]; //이전을 갱신
				}
				else { //오름차순 끝
					cnt += prev - C[i]; //현재까지 횟수 더함
					prev = C[i]; //이전 갱신
				}
			}
			else { //음수인 경우
				if (prev > 0) { //이전이 양수인 경우 - 부호 다름
					cnt += prev; //이전 수행 횟수를 더함
					prev = C[i]; //이전을 갱신
				}
				else if (prev > C[i]) { //음수로 내림차순인 경우
					prev = C[i]; //이전 갱신
				}
				else { //내림차순 끝
					cnt += abs(prev) - abs(C[i]); //현재까지 횟수 더함
					prev = C[i]; //이전 갱신
				}
			}
		}
		//마지막 남은 탭 횟수 추가
		cnt += abs(prev);
		cout << cnt << '\n';
	}

	return 0;
}