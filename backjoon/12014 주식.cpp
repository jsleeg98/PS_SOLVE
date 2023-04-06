//���̵� : ���2
//���� : 19:15
//�� :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, K;
		cin >> N >> K;
		vector<int> arr;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}
		vector<int> LIS;
		LIS.push_back(arr[0]);  // ���� ù��° �� �ٷ� LIS �迭�� �ֱ�
		for (int i = 1; i < N; i++) {
			if (LIS[LIS.size() - 1] < arr[i]) {  // LIS �迭�� �� ������ �������� ���� ū ���
				LIS.push_back(arr[i]);  // LIS �迭 ���� �߰�
			}
			else {  // �׷��� ���� ���
				int pos = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();  // LIS �迭���� �������� �� �̻��� ���� ������ ���� ù��° �ε���
				LIS[pos] = arr[i];  // �� ��ġ�� �������� ���� ��ġ�Ѵ�. -> �� ���� ���� �ٲ�� ��� LIS �� ���� ���� �ִ��� �۰� �������ָ� �̴� LIS�� ���� �� �ִ� �����̴�.
			}
		}
		cout << "Case #" << t + 1 << '\n';
		if (LIS.size() >= K) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}