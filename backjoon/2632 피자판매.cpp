//���̵� : ���2
//���� : 
//�� :
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

// arr ���ڷ� ���� �� �ִ� ��� ����� �� ã�� �Լ�
deque<int> make_case(deque<int> arr) {
	deque<int> all_case;
	
	for (int i = 0; i < arr.size(); i++) {
		int sum = 0;
		for (int j = 0; j < arr.size() - 1; j++) {  // ��� ������ �� ���� �������� �ѹ��� ����
			sum += arr[j];  // �������� ���� ����� �� ����
			all_case.push_back(sum);
		}
		int tmp = arr.front(); //���� ������ �ڷ� �ű�鼭 �ݺ�
		arr.pop_front();
		arr.push_back(tmp);
	}
	int sum = 0; //select all pizza pieces
	for (int j = 0; j < arr.size(); j++) {
		sum += arr[j];
	}
	all_case.push_back(sum);

	//for (int i = 0; i < all_case.size(); i++) {
	//	cout << all_case[i] << " ";
	//}

	return all_case;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> pizza_a;
	deque<int> pizza_b;
	int pizza_size;
	cin >> pizza_size;
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		pizza_a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pizza_b.push_back(tmp);
	}

	deque<int> pizza_a_case = make_case(pizza_a);
	sort(pizza_a_case.begin(), pizza_a_case.end());  // �̺� Ž���� ���� ����
	deque<int> pizza_b_case = make_case(pizza_b);
	sort(pizza_b_case.begin(), pizza_b_case.end());  // �̺� Ž���� ���� ����

	int result = 0;
	for (int i = 1; i < pizza_size; i++) {
		int pizza_a_size = i;
		int pizza_b_size = pizza_size - pizza_a_size;

		int a_upper = upper_bound(pizza_a_case.begin(), pizza_a_case.end(), pizza_a_size) - pizza_a_case.begin();
		int a_lower = lower_bound(pizza_a_case.begin(), pizza_a_case.end(), pizza_a_size) - pizza_a_case.begin();
		int a_case = a_upper - a_lower;  // ã�� ���� ũ���� ����

		int b_upper = upper_bound(pizza_b_case.begin(), pizza_b_case.end(), pizza_b_size) - pizza_b_case.begin();
		int b_lower = lower_bound(pizza_b_case.begin(), pizza_b_case.end(), pizza_b_size) - pizza_b_case.begin();
		int b_case = b_upper - b_lower;  // ã�� ���� ũ���� ����

		result += a_case * b_case;  // �����̱� ������ ��
	}
	// �ϳ��� ���ڷθ� ������ �����ϴ� ���
	int a_upper = upper_bound(pizza_a_case.begin(), pizza_a_case.end(), pizza_size) - pizza_a_case.begin();
	int a_lower = lower_bound(pizza_a_case.begin(), pizza_a_case.end(), pizza_size) - pizza_a_case.begin();
	result += a_upper - a_lower;  

	int b_upper = upper_bound(pizza_b_case.begin(), pizza_b_case.end(), pizza_size) - pizza_b_case.begin();
	int b_lower = lower_bound(pizza_b_case.begin(), pizza_b_case.end(), pizza_size) - pizza_b_case.begin();
	result += b_upper - b_lower;

	cout << result << '\n';



	return 0;
}