//���� 15:50
//�� 17:16

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	vector<int> ans;
	int x1, y1, r1, x2, y2, r2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//l�� �߽� ������ �Ÿ��� double�� �����ؾ� �´�.
		//int�� �����ϴ� ��� �Ҽ��ڸ��� ������ ����ε� �񱳰� �Ұ����ϱ� ����
		double l = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (r1 == r2 && l == 0) { //������ ������ ������ ���
			ans.push_back(-1);
		}
		else if (r1 + r2 == l || abs(r1 - r2) == l) { //����, �����ϴ� ���
			ans.push_back(1);
		}
		else if (abs(r1 - r2) < l && l < r1 + r2) { //������ 2���� ���
			ans.push_back(2);
		}
		else { //������
			ans.push_back(0);
		}

		
		
		
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}


	return 0;
}