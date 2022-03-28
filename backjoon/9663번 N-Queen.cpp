//시간 초과
//난이도 : 골드5
//시작 : 
//끝 :
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> final_result;

bool is_available(vector<int> current_candidate, int current_col) {
	int current_row = current_candidate.size();
	for (int i = 0; i < current_row; i++) {
		if (current_candidate[i] == current_col || abs(current_candidate[i] - current_col) == current_row - i) {
			return false;
		}
	}
	return true;
}

void DFS(int N, int current_row, vector<int> current_candidate) {
	if (current_row == N) {
		final_result.push_back(current_candidate);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (is_available(current_candidate, i)) {
			current_candidate.push_back(i);
			DFS(N, current_row + 1, current_candidate);
			current_candidate.pop_back();
		}
	}
}

void solve_n_queens(int N) {
	vector<int> current_candidate;
	DFS(N, 0, current_candidate);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	solve_n_queens(N);
	/*for (int i = 0; i < final_result.size(); i++) {
		for (int j = 0; j < N; j++) {
			cout << final_result[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << final_result.size() << '\n';

	return 0;
}