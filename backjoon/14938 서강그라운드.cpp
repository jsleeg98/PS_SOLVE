//난이도 : 골드4
//시작 : 11:06
//끝 :
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> a[101]; //노드별 연결리스트 벡터
int INF = 987654321; //무한 정의


int* dijkstra(int d[], int start) { //입력으로 최단 거리 저장 배열과 시작노드 받음
	d[start] = 0; //시작 노드 거리 0
	priority_queue<pair<int, int>> pq; //우선순위 큐 사용
	pq.push(make_pair(start, 0));

	while (!pq.empty()) { //우선 순위 큐가 빌 때 까지 반복
		int current = pq.top().first; //현재 노드
		int distance = pq.top().second; //현재 노드 거리
		pq.pop();
		if (d[current] < distance) continue; //최단 거리 배열의 값이 현재 거리보다 작으면 바로 패스
		for (int i = 0; i < a[current].size(); i++) { //연결되어 있는 모든 인접 노드에 대해서
			int next = a[current][i].first; //다음 노드 번호
			int nextDistance = a[current][i].second + distance; //거쳐 가는 경우 거리
			if (nextDistance < d[next]) { //거쳐가는 경우가 현재 최단 거리보다 작은경우
				d[next] = nextDistance; //최단 거리 배열 업데이트
				pq.push(make_pair(next, nextDistance)); //추후 검증을 위해 우선순위 큐에 push
			}
		}
	}
	//for (int i = 1; i <= 5; i++) {
	//	cout << d[i] << " ";
	//}
	//cout << '\n';
	return d; //최단 거리 배열 반환

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r;//지역개수, 수색범위, 길의 개수
	cin >> n >> m >> r;

	//아이템 개수 입력
	int item[101] = { 0 };
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	//길 입력
	for (int i = 0; i < r; i++) {
		int start;
		int end;
		int distance;
		cin >> start >> end >> distance;
		a[start].push_back(make_pair(end, distance));
		a[end].push_back(make_pair(start, distance));
	}

	int max_item = 0; //최대 아이템 개수 저장
	for (int i = 1; i <= n; i++) {
		int d[101] = { 0 }; //최단 거리 배열
		for (int i = 1; i <= n; i++) { //거리를 모두 무한으로 초기화
			d[i] = INF;
		}
		int* tmp_d = dijkstra(d, i); //출발 지점으로부터 다익스트라 알고리즘 사용 후 배열을 받는다.
		int tmp_item = 0; //현재 위치에서 얻을 수 있는 아이템 개수 저장 
		/*for (int j = 1; j <= n; j++) {
			cout << tmp_d[j] << " ";
		}
		cout << '\n';*/
		for (int j = 1; j <= n; j++) { //수색 가능 범위 내에 있는 아이템만 수집하여 저장
			if (tmp_d[j] <= m) {
				tmp_item += item[j];
			}
		}
		//cout << i << " " << tmp_item << '\n';
		if (max_item < tmp_item) { //수집가능한 최대 아이템 개수만 저장
			max_item = tmp_item;
		}
	}

	cout << max_item << '\n';

	return 0;
}