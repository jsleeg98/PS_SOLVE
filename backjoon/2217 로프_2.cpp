//≥≠¿Ãµµ : 


#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> rope;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		rope.push_back(tmp);
	}

	sort(rope.begin(), rope.end());
	int result = rope[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		int k = N - i;
		if (rope[i] * k > result) {
			result = rope[i] * k;
		}
	}

	cout << result << '\n';


	return 0;
}