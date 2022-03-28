//���� : 22:43
//�� : 23:07
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char input_map[101][101]; //�Է� ��
	int visited_map[101][101] = { 0 }; //�湮 �� ǥ��
	queue<pair<int, int>> queue; //���� ��ǥ ������ ť
	int distance_map[101][101] = { 0 }; //�Ÿ� ���� ��
	
	//��, ��, ��, ��
	int dw[4] = {1, 0, -1, 0}; //w�� �����̴� �Ÿ�
	int dh[4] = {0, 1, 0, -1}; //h�� �����̴� �Ÿ�
	
	string line[101]; //�Է� ���� string �迭
	int N, M; //��, �� ����
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //�Է� ����
		cin >> line[i];
	}

	//��, ���� ������ input_map�� �� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			input_map[i][j] = line[i][j - 1];
		}
	}

	distance_map[1][1] = 1; //ù ���� ��ǥ �Ÿ��� 1
	visited_map[1][1] = 1; //ù ���� ��ǥ �湮 ó��
	queue.push(make_pair(1, 1)); //ù ���� ��ǥ ť�� ����
	while (queue.size() != 0) { //ť�� �� �� ���� �ݺ�
		int h = queue.front().first; //���� ��ǥ h ��
		int w = queue.front().second; //���� ��ǥ w ��
		queue.pop(); //ť���� pop

		for (int i = 0; i < 4; i++) {
			if (w + dw[i] > 0 && w + dw[i] < M + 1 
				&& h + dh[i] > 0 && h + dh[i] < N + 1) { //���� ����� �ʴ� ���
				if (input_map[h + dh[i]][w + dw[i]] == '1') { //���� ���� �ƴ� ��� 
					if (visited_map[h + dh[i]][w + dw[i]] == 0) { //�湮�� ��ǥ�� �ƴ� ���
						visited_map[h + dh[i]][w + dw[i]] = 1; //�湮 ó��
						distance_map[h + dh[i]][w + dw[i]] = distance_map[h][w] + 1; //���� ��ǥ�Ÿ����� 1 ���� �Ÿ� ����
						queue.push(make_pair(h + dh[i], w + dw[i])); //���� ��ǥ ť�� ����
				}
				
				}
			}
		}
	}

	//���� ��ġ���� ��� ���������� �Ÿ� ���
	cout << distance_map[N][M] << '\n'; 

	return 0;
}