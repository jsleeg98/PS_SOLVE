//난이도 : 골드4

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//// 오름차순 우선순위 큐
	//priority_queue<int, vector<int>, greater<int>> pq;  
	//int N;
	//cin >> N;
	//for (int i = 0; i < N; i++) {
	//	int tmp;
	//	cin >> tmp;
	//	pq.push(tmp);
	//}
	//
	//// 더할 때 가장 작은 비교 횟수를 더해가는 것
	//// 이렇게 만든 카드 묶음을 다시 배열에 넣고 오름차순 정렬
	//// 배열에 넣으면 바로 정렬을 해주는 것이 우선순위 큐

	//int result = 0;  // 비교 횟수
	//while (pq.size() > 1) {  // size가 2개 이상일 때
	//	int a = pq.top();  // 가장 작은 원소
	//	pq.pop();
	//	int b = pq.top();  // 그 다음 작은 원소
	//	pq.pop();
	//	pq.push(a + b);  // 합을 오름차순 우선순위 큐에 넣기
	//	result += a + b;  // 비교 횟수 추가
	//}

	//cout << result << '\n';

	int N;
	cin >> N;

	vector<int> card;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		card.push_back(tmp);
	}

	sort(card.begin(), card.end(), greater<int>());
	//reverse(card.begin(), card.end());
	int result = 0;
	while (card.size() > 1) {
		int a = card.back();
		card.pop_back();
		int b = card.back();
		card.pop_back();
		result += a + b;
		card.push_back(a + b);
		sort(card.begin(), card.end(), greater<int>());
	}

	cout << result << '\n';
	

	return 0;
}