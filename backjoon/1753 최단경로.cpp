//난이도 : 골드4
//시작 : 18:01
//끝 :
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#define MAX 20001
#define INF 987654321

using namespace std;

vector<pair<int, int>> a[MAX];

int dist[MAX] = { 0 };

void init_distance() {
	for (int i = 0; i < MAX; i++) {
		dist[i] = INF;
	}
}

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int current = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		if (dist[current] < cur_dist) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDist = cur_dist + a[current][i].second;
			if (nextDist < dist[next]) {
				dist[next] = nextDist;
				pq.push({ nextDist, next });
			}
		}
		//for (int i = 1; i <= 5; i++) {
		//	cout << setw(3) << i;
		//}
		//cout << '\n';
		//for (int i = 1; i <= 5; i++) {
		//	cout << setw(3) << dist[i];
		//}
		//cout << '\n';
		//cout << "-------------";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init_distance();
	
	int V, E;
	cin >> V >> E;
	int start;
	cin >> start;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back({ v, w });
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}




	return 0;
}