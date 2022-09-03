//난이도 : 실버3
//시작 : 01:01
//끝 : 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[8] = { 0 }; // 결과 배열
int num[8] = { 0 }; // 입력 배열

// 같은 숫자를 고르지 않도록 확인하는 함수
bool is_available(int cur) {
	for (int i = 0; i < cur; i++) {
		if (arr[i] > arr[cur]) { // 같은게 있다면
			return false; // 거짓
		}
	}
	return true; // 없으면 참
}

void DFS(int N, int M, int cur) {
	if (cur == M) { // 정해진 길이만큼 골랐을 떄 출력
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		arr[cur] = num[i]; // 현 위치에 숫자 할당
		if (is_available(cur)) { // 동일한 숫자를 할당하지 않은 경우
			DFS(N, M, cur + 1); // 다음 숫자를 찾음
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	DFS(N, M, 0);

	return 0;
}