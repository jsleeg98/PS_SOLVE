//난이도 : 골드 3

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct lecture{
	int d;
	int p;
};

// p가 작은 순서로 정렬하고 같다면 d가 작은 순서로 정렬
struct compare_1 {
	bool operator()(const lecture& a, const lecture& b) {
		if (a.p == b.p) {
			return a.d > b.d;
		}
		else {
			return a.p > b.p;
		}
	}
};

// d가 작은 순서로 정렬하고 같다면 p가 큰 순서로 정렬
struct compare_2 {
	bool operator()(const lecture& a, const lecture& b) {
		if (a.d == b.d) {
			return a.p < b.p;
		}
		else {
			return a.d > b.d;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<lecture, vector<lecture>, compare_2> pq;
	priority_queue<lecture, vector<lecture>, compare_1> pq_result;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		lecture tmp;
		cin >> tmp.p >> tmp.d;
		pq.push(tmp);
	}

	//while (!pq.empty()) {
	//	cout << pq.top().d << " " << pq.top().p << '\n';
	//	pq.pop();
	//}

	int day = 0;
	while (!pq.empty()) {  
		if (day < pq.top().d) { // 해당 날짜에 강연을 할 수 있는 경우
			lecture tmp = pq.top();
			pq_result.push(tmp);  //강연 큐에 추가
			pq.pop();
			day += 1;  // 날짜 +1
		}
		else {  // 해당 날짜에 강연을 할 수 없는 경우
			if (pq_result.top().p < pq.top().p) {  // 기존 강연을 하지 않고 현재 강연을 하는 것이 더 이익인 경우
				pq_result.pop();  
				pq_result.push(pq.top());  // 강연 큐 업데이트 -> 가장 이익인 상태
				pq.pop();
			}
			else {  // 기존 강연을 하는게 이익인 경우 
				pq.pop();
			}
		}
	}

	// 강연 큐의 이익 합
	int total = 0;
	while (!pq_result.empty()) {
		total += pq_result.top().p;
		pq_result.pop();
	}

	cout << total << '\n';

	return 0;
}