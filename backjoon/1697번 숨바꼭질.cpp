//���̵� : �ǹ�1
//���� : 14:35
//�� : 15:35
#include <iostream>
#include <queue>


using namespace std;

//ũ�Ⱑ ū �迭�̱� ������ �ݵ�� ���������� �����ؾ��Ѵ�.
int visited[100001] = { 0 }; //�湮 �迭

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int, int>> q; //ť ���� <���� ��ġ, ������ Ƚ��>
	
	int N, K;
	cin >> N >> K;
	visited[N] = 1; //ó�� ��ġ �湮 ó��
	q.push(make_pair(N, 0)); //ť�� ���� ��ġ, ������ Ƚ�� push
	bool stop = false; //stop false�� �ʱ�ȭ
	int result; //���
	while (q.size() != 0 && stop == false) { //ť�� ������� �ʰ� stop�� false�ΰ�� �ݺ�
		int node = q.front().first; //ť�� �� ��ġ ��� 
		int depth = q.front().second; //ť�� �� ������ Ƚ�� ���
		q.pop(); //ť pop
		if (node == K) { //��ó�� N�� K�� ��ġ�� ���� ���
			result = depth; //0�� ����
			break; //����
		}
		int a[3] = { node - 1, node + 1, node * 2 }; //������ ���
		for (int i = 0; i < 3; i++) {
			if (a[i] <= 100000) { //100000 ���� ��ġ ����� ���� ���
				if (a[i] == K) { //������ ���
					stop = true; //���� 
					result = depth + 1; //���� Ƚ�� ��� ����
					break;
				}
				else if (visited[a[i]] == 0) { //�湮���� ���� ��ġ�� ���
					q.push(make_pair(a[i], depth + 1)); //ť�� push
					visited[a[i]] = 1; //�湮 ó��
				}
				
			}
		}
	}
	
	cout << result << '\n'; //��� ���

	return 0;
}