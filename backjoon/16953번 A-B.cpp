//���� : 12:11
//�� : 12:50
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<long long int, int>> q;
	long long int A, B; //10^9���� �Է��� �����⶧���� long long int�� �ؾ��Ѵ�.
	cin >> A >> B;
	q.push(make_pair(A, 1)); //���� �� �ڴ� Ʈ���� ���̸� �����ϸ� Ʈ���� ���̴� Ƚ���� �ǹ��Ѵ�.
	while (1) {
		long long int tmp_value = q.front().first;
		int tmp_cnt = q.front().second;
		q.pop();
		long long int a[2];
		a[0] = tmp_value * 10 + 1;
		a[1] = tmp_value * 2;
		for (int i = 0; i < 2; i++) {
			if (a[i] == B) {
				cout << tmp_cnt + 1 << '\n';
				return 0;
			}
			else if (a[i] < B) {
				q.push(make_pair(a[i], tmp_cnt + 1));
			}
		}
		if (q.size() == 0) {
			cout << -1 << '\n';
			return 0;
		}
	}
	

	return 0;
}