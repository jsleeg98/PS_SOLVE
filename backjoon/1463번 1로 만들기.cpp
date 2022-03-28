//���̵� : �ǹ�3
//���� : 20:20
//�� : 20:40
#include <iostream>
#include <queue>

using namespace std;

int visited[1000001] = {0}; //�湮 �迭 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int, int>> q;
	int X; //��ǥ ��
	cin >> X;

	//1���� �����Ͽ� ��ǥ ������ ���� ���
	visited[1] = 1; //1�� �湮 ó��
	q.push(make_pair(1, 0)); //1, count 1 push
	bool stop = false;
	int result;
	while (q.size() != 0 && stop == false) {
		int value = q.front().first;
		int count = q.front().second;
		q.pop();
		if (value == X) { //�Է��� 1�� ���� ���
			result = 0; //��� 0���� ����
			break;
		}
		int a[3] = { value + 1, value * 2, value * 3 }; //3���� ����� �� �����
		for (int i = 0; i < 3; i++) {
			if (a[i] <= 1000000) { //1000000���� ���� ��츸 ���� visited �迭�� 1000000������ ó�� �����ϴ�.
				if (a[i] == X) { //��ǥ ���� ���� ���
					stop = true; //���� ó��
					result = count + 1; //��� ó��
				}
				if (visited[a[i]] == 0) { //�湮���� ���� ���
					q.push(make_pair(a[i], count + 1)); //ť�� push
					visited[a[i]] = 1; //�湮 ó��
				}
			}
		}
	}
	//��� ���
	cout << result << '\n';


	return 0;
}