//난이도 : 실버3
//시작 : 20:20
//끝 : 20:40
#include <iostream>
#include <queue>

using namespace std;

int visited[1000001] = {0}; //방문 배열 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int, int>> q;
	int X; //목표 값
	cin >> X;

	//1부터 시작하여 목표 값으로 가는 방식
	visited[1] = 1; //1을 방문 처리
	q.push(make_pair(1, 0)); //1, count 1 push
	bool stop = false;
	int result;
	while (q.size() != 0 && stop == false) {
		int value = q.front().first;
		int count = q.front().second;
		q.pop();
		if (value == X) { //입력이 1이 들어온 경우
			result = 0; //결과 0으로 갱신
			break;
		}
		int a[3] = { value + 1, value * 2, value * 3 }; //3가지 경우의 수 만들기
		for (int i = 0; i < 3; i++) {
			if (a[i] <= 1000000) { //1000000보다 작은 경우만 수행 visited 배열이 1000000까지만 처리 가능하다.
				if (a[i] == X) { //목표 값이 나온 경우
					stop = true; //종료 처리
					result = count + 1; //결과 처리
				}
				if (visited[a[i]] == 0) { //방문하지 않은 경우
					q.push(make_pair(a[i], count + 1)); //큐에 push
					visited[a[i]] = 1; //방문 처리
				}
			}
		}
	}
	//결과 출력
	cout << result << '\n';


	return 0;
}