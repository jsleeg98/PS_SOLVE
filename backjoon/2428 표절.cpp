//난이도 : 실버3
//시작 : 16:30
//끝 : 17:20
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> F;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		F.push_back(tmp);
	}

	sort(F.begin(), F.end());  //오름차순 정렬

	long long result = 0;
	for (int i = F.size() - 1; i > 0; i--) {
		double thres = (double)F[i] * (double)9 / (double)10;  // double은 소수점 이하 15자리, float는 소수점 이하 6자리
		long long idx = lower_bound(F.begin(), F.end(), thres) - F.begin();
		result += (i - idx); 
	}

	cout << result << '\n';

	return 0;
}