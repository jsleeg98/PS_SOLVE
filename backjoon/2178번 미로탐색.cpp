//시작 : 22:43
//끝 : 23:07
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char input_map[101][101]; //입력 맵
	int visited_map[101][101] = { 0 }; //방문 맵 표시
	queue<pair<int, int>> queue; //다음 좌표 저장할 큐
	int distance_map[101][101] = { 0 }; //거리 저장 맵
	
	//동, 남, 서, 북
	int dw[4] = {1, 0, -1, 0}; //w축 움직이는 거리
	int dh[4] = {0, 1, 0, -1}; //h축 움직이는 거리
	
	string line[101]; //입력 저장 string 배열
	int N, M; //행, 열 저장
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //입력 받음
		cin >> line[i];
	}

	//행, 열로 나누어 input_map에 맵 저장
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			input_map[i][j] = line[i][j - 1];
		}
	}

	distance_map[1][1] = 1; //첫 시작 좌표 거리는 1
	visited_map[1][1] = 1; //첫 시작 좌표 방문 처리
	queue.push(make_pair(1, 1)); //첫 시작 좌표 큐에 삽입
	while (queue.size() != 0) { //큐가 빌 때 까지 반복
		int h = queue.front().first; //현재 좌표 h 값
		int w = queue.front().second; //현재 좌표 w 값
		queue.pop(); //큐에서 pop

		for (int i = 0; i < 4; i++) {
			if (w + dw[i] > 0 && w + dw[i] < M + 1 
				&& h + dh[i] > 0 && h + dh[i] < N + 1) { //맵을 벗어나지 않는 경우
				if (input_map[h + dh[i]][w + dw[i]] == '1') { //맵의 벽이 아닌 경우 
					if (visited_map[h + dh[i]][w + dw[i]] == 0) { //방문한 좌표가 아닌 경우
						visited_map[h + dh[i]][w + dw[i]] = 1; //방문 처리
						distance_map[h + dh[i]][w + dw[i]] = distance_map[h][w] + 1; //이전 좌표거리보다 1 더한 거리 저장
						queue.push(make_pair(h + dh[i], w + dw[i])); //다음 좌표 큐에 저장
				}
				
				}
			}
		}
	}

	//도착 위치에서 출발 지점까지의 거리 출력
	cout << distance_map[N][M] << '\n'; 

	return 0;
}