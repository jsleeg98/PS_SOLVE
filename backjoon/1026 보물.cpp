//난이도 : 실버 4

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> A;
	vector<int> B;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		B.push_back(tmp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int result = 0;
	for (int i = 0; i < N; i++) {
		result += A[i] * B[i];
	}

	cout << result << '\n';



	return 0;
}