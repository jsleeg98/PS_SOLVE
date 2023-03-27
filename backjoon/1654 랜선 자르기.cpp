//���̵� : �ǹ� 2
//���� : 18:50
//�� :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;  // �ʿ��� ������ ����
	int K;  // ������ ����

	vector<long long> lan;  // ������ �ִ� ���� �迭

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		lan.push_back(tmp);
	}

	sort(lan.begin(), lan.end());  // ������ �ִ� ���� �������� ����

	long long L = 1;  // Left�� 0���� �ʱ�ȭ
	long long R = lan[lan.size() - 1];  // Right�� ������ �ִ� ���� �� ���� �� ������ �ʱ�ȭ -> ª�� ������ �ϸ� 1�� ���� ������ ������ ã�� ����
	long long result = 0;

	while (L <= R) {
		//cout << L << "---" << R << '\n';
		long long mid = (L + R) / 2;
		int cnt = 0;
		for (int i = 0; i < lan.size(); i++) {
			cnt += lan[i] / mid;
		}
		if (cnt < N) {
			R = mid - 1;
		}
		else if (cnt >= N) {
			L = mid + 1;
			if (mid > result) {
				result = mid;
			}
		}
		//cout << tmp_result << '\n';
	}

	cout << result << '\n';
  	return 0;
}