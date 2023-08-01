//난이도 : 실버 5

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	priority_queue<int> pq;
	int N;
	int dasom;
	int cnt = 0;
	cin >> N;
	cin >> dasom;
	for (int i = 1; i < N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	if (pq.size() > 0) {
		while (pq.top() >= dasom) {
			int tmp;
			tmp = pq.top();
			pq.pop();
			dasom += 1;
			tmp -= 1;
			pq.push(tmp);
			cnt += 1;
		}
	}
	
	cout << cnt << '\n';
	

	return 0;
}