//���̵� : �ǹ�1
//���� : 09:35
//�� : 09:57
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_oper[4] = { 0 }; 
int num[11] = { 0 };
int op[11] = { 0 };
vector<int> v_result;

int calc(int N, int op[]) { //������ ����ϴ� �Լ�
	int result = num[0];
	for (int i = 1; i < N; i++) {
		if (op[i - 1] == 0) { //0�� +
			result += num[i];
		}
		else if (op[i - 1] == 1) { //1�� -
			result -= num[i];
		}
		else if (op[i - 1] == 2) { //2�� *
			result *= num[i];
		}
		else if (op[i - 1] == 3) { //3�� /
			result /= num[i];
		}
	}
	return result;
}

bool is_available(int op) {
	if (num_oper[op] == 0) { //�ش� �����ڰ� �������� ���� ���
		return false;
	}
	num_oper[op]--; //�����ڸ� ��������� ���� ������ �ϳ� ����
	return true;
}

void DFS(int N, int cur) { //DFS
	if (N - 1 == cur) { //�����ڸ� ��� ä�� ���
		int result = calc(N, op); //��� ���
		v_result.push_back(result); //���� ����
		//cout << result << '\n';
	}
	for (int i = 0; i < 4; i++) { //��� ������ ����
		op[cur] = i;
		if (is_available(i)) {
			DFS(N, cur + 1); // DFS
			num_oper[i]++; //�ٸ� ����� ���� ã�� ���ؼ� ����� �����ڸ� �ٽ� �÷��ش�.
		}
		
	}
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> num_oper[i];
	}

	DFS(N, 0);

	cout << *max_element(v_result.begin(), v_result.end()) << '\n'; //���� �� �ִ밪 ���
	cout << *min_element(v_result.begin(), v_result.end()) << '\n'; //���� �� �ּҰ� ���


	return 0;
}