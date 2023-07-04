//난이도 : 골드5

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> pos;

	int N;
	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pos.push_back(tmp);
	}

	sort(pos.begin(), pos.end());  // 센서 위치별 정렬
	vector<int> dist;

	// 센서 간 거리 측정
	for (int i = 1; i < N; i++) {
		dist.push_back(pos[i] - pos[i - 1]);
	}

	sort(dist.begin(), dist.end());  // 센서 거리별 정렬
	
	// 집중국의 수신 가능 영역 길이의 최솟값은 
	// 최대한 뭉쳐있는 센서끼리 집중국이 담당하면 된다.
	// 이는 멀리 떨어져 있는 센서는 별개의 집중국이 담당하도록 하면 된다.
	// 이를 위해 집중국 개수-1 의 거리를 제외하여 거리를 모두 더하면 된다.
	
	// 결국 어떻게 센서를 집중국 개수만큼의 구역으로 나눌 것인가의 문제이며,
	// 이는 거리가 먼 것부터 별개의 구역으로 나눠간다고 생각하면 된다.
	int result = 0;
	for (int i = 0; i < N - K; i++) { 
		result += dist[i];
	}

	cout << result << '\n';

	return 0;
}