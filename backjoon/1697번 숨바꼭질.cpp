//난이도 : 실버1
//시작 : 14:35
//끝 : 15:35
#include <iostream>
#include <queue>


using namespace std;

//크기가 큰 배열이기 때문에 반드시 전역변수로 선언해야한다.
int visited[100001] = { 0 }; //방문 배열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int, int>> q; //큐 생성 <현재 위치, 움직인 횟수>
	
	int N, K;
	cin >> N >> K;
	visited[N] = 1; //처음 위치 방문 처리
	q.push(make_pair(N, 0)); //큐에 현재 위치, 움직인 횟수 push
	bool stop = false; //stop false로 초기화
	int result; //결과
	while (q.size() != 0 && stop == false) { //큐가 비어있지 않고 stop이 false인경우 반복
		int node = q.front().first; //큐의 앞 위치 얻기 
		int depth = q.front().second; //큐의 앞 움직인 횟수 얻기
		q.pop(); //큐 pop
		if (node == K) { //맨처음 N과 K의 위치가 같은 경우
			result = depth; //0이 저장
			break; //멈춤
		}
		int a[3] = { node - 1, node + 1, node * 2 }; //세가지 경우
		for (int i = 0; i < 3; i++) {
			if (a[i] <= 100000) { //100000 이전 위치 경우의 수만 고려
				if (a[i] == K) { //도착한 경우
					stop = true; //멈춤 
					result = depth + 1; //수행 횟수 결과 저장
					break;
				}
				else if (visited[a[i]] == 0) { //방문하지 않은 위치인 경우
					q.push(make_pair(a[i], depth + 1)); //큐에 push
					visited[a[i]] = 1; //방문 처리
				}
				
			}
		}
	}
	
	cout << result << '\n'; //결과 출력

	return 0;
}