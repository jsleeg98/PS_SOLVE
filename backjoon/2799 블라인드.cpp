//���̵� : �ǹ�4
//���� : 
//�� :
#include <iostream>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�ε��� 1���� ����ؾ��ϴ� ������ ��ó���� #�� ������ ������ result�� ���Ǿ������ �����̴�.
	int result[6] = { 0 }; //�ε��� 1���� ����ϸ� Ÿ���� �� ���� ����

	int M, N;
	cin >> M >> N;

	int type[101] = { 0 }; //�ε��� 1���� ���
	for (int i = 0; i < 1 + 5 * M; i++) {
		string tmp;
		cin >> tmp;
		if (tmp[1] == '#') { //���� ���� ������ �ʱ�ȭ
			for (int i = 1; i <= N; i++) {
				result[type[i]]++; //�ش� Ÿ�� ���� +1
				type[i] = 1; //���� ���� ���� �ʱ�ȭ �̶� �ϴ� ����ε尡 ���������� ���� 1�� ����� ����
			}
			continue; 
		}
		for (int i = 1; i <= 1 + 5 * N; i += 5) { //â���� �� ������ ��ġ�� Ȯ��
			if (tmp[i] == '*') { //����ε尡 ���� �ִٸ�
				type[1 + (i - 1) / 5]++; //������ +1�Ͽ� �ٸ� ������ ǥ��
			}
		}
	}

	// ��� ���
	for (int i = 1; i < 6; i++) {
		cout << result[i] << " ";
	}
	cout << '\n';

	return 0;
}