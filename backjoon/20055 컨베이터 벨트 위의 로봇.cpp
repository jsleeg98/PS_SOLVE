//���̵� : ���5
//���� : 
//�� :
#include <iostream>
#include <deque>

using namespace std;

int N, K;
deque<pair<int, int>> belt;
int broke = 0;

void print() {
	for (int i = 0; i < belt.size(); i++) {
		cout << belt[i].first << " ";
	}
	cout << '\n';
}

void rotate() {
	pair<int, int> tmp;
	tmp = belt.back(); //�� �ڿ��� ����
	belt.pop_back(); 
	belt.push_front(tmp); //�� ������ �ֱ�

}

void remove_robot() {
	//���� ��ġ�� �κ� �ִٸ� �ٷ� ����
	if (belt[N - 1].second == 1) {
		belt[N - 1].second = 0;
	}
}

void move_robot() {
	//���� �ø� �κ����� �����Ͽ� ���� ĭ�� ����ְ� �������� 0���� ũ��
	//�κ� �ű��
	for (int i = N - 1; i >= 0; i--) {
		if (belt[i].second == 1 && belt[i + 1].second == 0 && belt[i + 1].first > 0) {
			belt[i].second = 0; 
			belt[i + 1].second = 1;
			//cout << belt[i + 1].second << '\n';
			belt[i + 1].first -= 1;
			//cout << belt[i + 1].second << '\n';
			if (belt[i + 1].first == 0) {
				broke++;
			}
		}
	}
}

void load_robot() {
	// �� �տ� �������� 0���� ũ�ٸ�
	//�κ� �ø�
	if (belt[0].first > 0) {
		belt[0].second = 1;
		belt[0].first -= 1;
		if (belt[0].first == 0) {
			broke++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N * 2; i++) {
		int tmp;
		cin >> tmp;
		belt.push_back(make_pair(tmp, 0));
	}

	int result = 0;
	while (1) {
		result++;
		//print();
		rotate(); //�����̾� ������
		//print();
		remove_robot(); //�κ� ������
		move_robot(); //�κ� �����̱�
		remove_robot(); //�κ� ������
		load_robot();  //�κ� �ø���
		//print();
		if (broke >= K) { //������ �˻�
			break;
		}
	}

	//��� ���
	cout << result << '\n';

	return 0;
}