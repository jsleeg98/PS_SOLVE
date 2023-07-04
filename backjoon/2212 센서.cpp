//���̵� : ���5

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> pos;

	int N;
	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pos.push_back(tmp);
	}

	sort(pos.begin(), pos.end());  // ���� ��ġ�� ����
	vector<int> dist;

	// ���� �� �Ÿ� ����
	for (int i = 1; i < N; i++) {
		dist.push_back(pos[i] - pos[i - 1]);
	}

	sort(dist.begin(), dist.end());  // ���� �Ÿ��� ����
	
	// ���߱��� ���� ���� ���� ������ �ּڰ��� 
	// �ִ��� �����ִ� �������� ���߱��� ����ϸ� �ȴ�.
	// �̴� �ָ� ������ �ִ� ������ ������ ���߱��� ����ϵ��� �ϸ� �ȴ�.
	// �̸� ���� ���߱� ����-1 �� �Ÿ��� �����Ͽ� �Ÿ��� ��� ���ϸ� �ȴ�.
	
	// �ᱹ ��� ������ ���߱� ������ŭ�� �������� ���� ���ΰ��� �����̸�,
	// �̴� �Ÿ��� �� �ͺ��� ������ �������� �������ٰ� �����ϸ� �ȴ�.
	int result = 0;
	for (int i = 0; i < N - K; i++) { 
		result += dist[i];
	}

	cout << result << '\n';

	return 0;
}