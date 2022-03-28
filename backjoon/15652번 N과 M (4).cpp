//난이도 : 실버3
//시작 : 10:20
//끝 : 10:33
#include <iostream>

using namespace std;

int arr[9] = { 0 }; //수열 저장 배열

//백트래킹 pruning 과정
bool is_available(int cur) { 
	for (int i = 0; i < cur; i++) {
		if (arr[cur] < arr[i]) { //내림차순으로 될 경우 탈락
			return false;
		}
	}
	return true;
}

//DFS 탐색
void DFS(int N, int M, int cur) {
	if (M == cur) { //수열을 완성한 경우
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[cur] = i;
		if (is_available(cur)) { //pruning
			DFS(N, M, cur + 1); //다음 탐색
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