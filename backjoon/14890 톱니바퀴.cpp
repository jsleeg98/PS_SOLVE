//���̵� : ���5
//���� : 10:36
//�� : 11:23
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int wheel[5][8]; //��� ������ ���� ���� // 1������ 4�� �ε��� ���

//��� ȸ�� ��Ű�� �Լ�
void rotate(int wheel_num, int dir) {
	if (dir == 1) {//�ð� ���� ȸ���� ���
		int tmp = wheel[wheel_num][7];
		for (int i = 7; i > 0; i--) {
			wheel[wheel_num][i] = wheel[wheel_num][i - 1];
		}
		wheel[wheel_num][0] = tmp;
	}
	else if (dir == -1) { //�ݽð� ���� ȸ���� ���
		int tmp = wheel[wheel_num][0];
		for (int i = 0; i < 7; i++) {
			wheel[wheel_num][i] = wheel[wheel_num][i + 1];
		}
		wheel[wheel_num][7] = tmp;
	}
}

queue<pair<int, int>> check(int wheel_num, int dir) {
	queue<pair<int, int>> q;
	q.push(make_pair(wheel_num, dir)); //���� ��� ������ ť�� push
	
	if (wheel_num == 1) { //1���� ������ ���
		if (wheel[1][2] != wheel[2][6]) {//2�� �¹���
			dir *= -1;
			q.push(make_pair(2, dir)); //2�� �߰�
			if (wheel[2][2] != wheel[3][6]) { //3�� �¹���
				dir *= -1;
				q.push(make_pair(3, dir)); //3�� �߰�
				if (wheel[3][2] != wheel[4][6]) { //4�� �¹���
					dir *= -1;
					q.push(make_pair(4, dir)); //4�� �߰�
				}
			}
		}
	}
	else if (wheel_num == 2) {
		dir *= -1;
		if (wheel[2][6] != wheel[1][2]) {//1�� �¹���
			q.push(make_pair(1, dir));//1�� �߰�
		}
		if (wheel[2][2] != wheel[3][6]) { //3�� �¹���
			q.push(make_pair(3, dir));//3�� �߰�
			if (wheel[3][2] != wheel[4][6]) {//4�� �¹���
				dir *= -1;
				q.push(make_pair(4, dir));//4�� �߰�
			}
		}
	}
	else if (wheel_num == 3) {
		dir *= -1;
		if (wheel[3][2] != wheel[4][6]) {//4�� �¹���
			q.push(make_pair(4, dir)); //4�� �߰�
		}
		if (wheel[3][6] != wheel[2][2]) {//2�� �¹���
			q.push(make_pair(2, dir));//2�� �߰�
			if (wheel[2][6] != wheel[1][2]) {//1�� �¹���
				dir *= -1;
				q.push(make_pair(1, dir)); //1�� �߰�
			}
		}
	}
	else if (wheel_num == 4) {
		if (wheel[4][6] != wheel[3][2]) { //3�� �¹���
			dir *= -1;
			q.push(make_pair(3, dir)); //3�� �߰�
			if (wheel[3][6] != wheel[2][2]) { //2�� �¹���
				dir *= -1;
				q.push(make_pair(2, dir));//2�� �߰�
				if (wheel[2][6] != wheel[1][2]) {//1�� �¹���
					dir *= -1;
					q.push(make_pair(1, dir)); //1�� �߰�
				}
			}
		}
	}
	return q;
}

//ť�� ����ִ� ȸ�� ������ ���� ��� ������ ȸ����Ű�� �Լ�
void wheel_rotate(queue<pair<int, int>> q) {
	while (!q.empty()) {
		int wheel_num = q.front().first;
		int dir = q.front().second;
		q.pop();
		rotate(wheel_num, dir); //��Ϲ��� ȸ��
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//string���� ������ �Է� �ް� �̸� ���ڷ� �ٲٱ� ���� 48�� ���� �ٲ۴�.
	//�׸��� �̸� int �迭�� �ִ´�.
	for (int i = 1; i <= 4; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = (int)tmp[j] - 48;
		}
	}

	//for (int i = 1; i <= 4; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		cout << wheel[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int wheel_num, dir;
		cin >> wheel_num >> dir;
		queue<pair<int, int>> q;
		q = check(wheel_num, dir); //��� ���� �¹��� Ȯ���ϱ�
		wheel_rotate(q); //��Ϲ��� ������
	}

	//for (int i = 1; i <= 4; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		cout << wheel[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	//��� ����
	int result = 0;
	for (int i = 1; i <= 4; i++) {
		if (wheel[i][0] == 1) { //S�� �̶�� 
			result += pow(2, i-1); //2�� �����Ͽ� ���� ��
		}
	}

	cout << result << '\n'; //���� ���

	return 0;
}