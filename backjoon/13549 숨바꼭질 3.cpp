//난이도 : 골드5
//시작 : 16:40
//끝 : 17:52
#include <iostream>
#include <queue>
#define MAX 100001  // 최대 위치

using namespace std;

// 우선순위 큐로 현재 시간이 작은 것이 우선으로 정렬
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// 방문한 위치 저장, 중복 위치 반복 방지
bool visited[MAX] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	pq.push({ 0, N });  // {걸린 시간, 위치}
	visited[N] = true;  // 방문 처리
	int result = 0;  // 결과 걸린 시간 저장

	while (!pq.empty()) {
		pair<int, int> tmp = pq.top();  //걸린 시간이 가장 적은 것부터 우선하여 나옴
		pq.pop();
		int cur_pos = tmp.second;  //현재 위치
		int cur_time = tmp.first;  //현재 위치에서 걸린 시간
		//cout << cur_pos << " " << cur_time << '\n';
		if (cur_pos == K) {  //현재 위치와 찾는 위치와 같으면
			result = cur_time;  //결과 저장 후
			break;  //반복 종료
		}

		if (cur_pos * 2 < MAX && !visited[cur_pos * 2]) {  // 2배 다음 위치가 최대 위치보다 작고 이미 방문하지 않은 곳인 경우
			pq.push({ cur_time, cur_pos * 2 });
			visited[cur_pos * 2] = true;
		}
		if (cur_pos + 1 < MAX && !visited[cur_pos + 1]) {  // +1 다음 위치가 최대 위치보다 작고 이미 방문하지 않은 곳인 경우
			pq.push({ cur_time + 1, cur_pos + 1 });  // {현재 걸린 시간 + 1, 현재 위지 + 1}
			visited[cur_pos + 1] = true;
		}
		if (cur_pos - 1 >= 0 && !visited[cur_pos - 1]) {  // -1 다음 위치가 0보다 크거나 같고 이미 방문하지 않은 곳인 경우
			pq.push({ cur_time + 1, cur_pos - 1 });  // {현재 걸린 시간 + 1, 현재 위치 -1}
			visited[cur_pos - 1] = true;
		}
	}

	cout << result << '\n';


	return 0;
}