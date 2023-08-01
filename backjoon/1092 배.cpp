//≥≠¿Ãµµ : ∞ÒµÂ 5

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> cranes;
	vector<int> boxes;
	vector<int> boxes_2;

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		cranes.push_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		boxes.push_back(tmp);
	}
	sort(cranes.begin(), cranes.end(), greater<>());
	sort(boxes.begin(), boxes.end(), greater<>());

	int cnt = 0;
	int time = 0;
	if (cranes[0] < boxes[0]) {
		cout << -1;
		return 0;
	}
	while (!boxes.empty()) {
		time += 1;
		for (int i = 0; i < cranes.size(); i++) {
			for (int j = 0; j < boxes.size(); j++) {
				if (cranes[i] >= boxes[j]) {
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}
	}
	cout << time << '\n';
	


	return 0;
}