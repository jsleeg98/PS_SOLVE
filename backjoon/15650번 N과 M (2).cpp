//난이도 : 실버3
//시작 : 09:38
//끝 : 09:39
#include <iostream>

using namespace std;

int arr[8] = { 0 };

//백트래킹 pruning 부분
bool is_available(int cur) {
	for (int i = 0; i < cur; i++) {
		if (arr[cur] == arr[i] || arr[cur] < arr[i]) { //이전에 나온 것과 겹치거나 더 작으면 탈락
			return false;
		}
	}
	return true;
}

//DFS 구현 부분
void DFS(int N, int M, int cur) {
	if (M == cur) { //수열을 만드는데 성공한 경우 모두 출력
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= N; i++) { //숫자를 넣어보고 맞는지 확인
		arr[cur] = i;
		if (is_available(cur)) {
			DFS(N, M, cur + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	DFS(N, M, 0);

	return 0;
}