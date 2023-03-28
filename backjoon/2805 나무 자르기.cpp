//난이도 : 실버2
//시작 : 10:41
//끝 :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 나무의 개수
	int M; //가져가려는 나무의 수

	cin >> N >> M;

	vector<long long int>trees;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		trees.push_back(tmp);
	}


	sort(trees.begin(), trees.end());
	
	int result = 0;
	long long int L = 0;
	long long int R = trees[trees.size() - 1];

	while (L <= R) {
		long long int mid = (L + R) / 2;
		int tmp_M = 0;
		for(int i = 0; i < trees.size(); i++) {
			long long int tmp = trees[i] - mid;
			if(tmp >= 0){
				tmp_M += tmp;
			}
		}
		//cout << mid << '\n';
		if (tmp_M < M) {
			R = mid - 1;
		}
		else {
			L = mid + 1;
			if (mid > result) {
				result = mid;
			}
		}
	}

	cout << result << '\n';

	return 0;
}