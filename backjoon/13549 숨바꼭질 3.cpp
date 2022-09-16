//���̵� : ���5
//���� : 16:40
//�� : 17:52
#include <iostream>
#include <queue>
#define MAX 100001  // �ִ� ��ġ

using namespace std;

// �켱���� ť�� ���� �ð��� ���� ���� �켱���� ����
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// �湮�� ��ġ ����, �ߺ� ��ġ �ݺ� ����
bool visited[MAX] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	pq.push({ 0, N });  // {�ɸ� �ð�, ��ġ}
	visited[N] = true;  // �湮 ó��
	int result = 0;  // ��� �ɸ� �ð� ����

	while (!pq.empty()) {
		pair<int, int> tmp = pq.top();  //�ɸ� �ð��� ���� ���� �ͺ��� �켱�Ͽ� ����
		pq.pop();
		int cur_pos = tmp.second;  //���� ��ġ
		int cur_time = tmp.first;  //���� ��ġ���� �ɸ� �ð�
		//cout << cur_pos << " " << cur_time << '\n';
		if (cur_pos == K) {  //���� ��ġ�� ã�� ��ġ�� ������
			result = cur_time;  //��� ���� ��
			break;  //�ݺ� ����
		}

		if (cur_pos * 2 < MAX && !visited[cur_pos * 2]) {  // 2�� ���� ��ġ�� �ִ� ��ġ���� �۰� �̹� �湮���� ���� ���� ���
			pq.push({ cur_time, cur_pos * 2 });
			visited[cur_pos * 2] = true;
		}
		if (cur_pos + 1 < MAX && !visited[cur_pos + 1]) {  // +1 ���� ��ġ�� �ִ� ��ġ���� �۰� �̹� �湮���� ���� ���� ���
			pq.push({ cur_time + 1, cur_pos + 1 });  // {���� �ɸ� �ð� + 1, ���� ���� + 1}
			visited[cur_pos + 1] = true;
		}
		if (cur_pos - 1 >= 0 && !visited[cur_pos - 1]) {  // -1 ���� ��ġ�� 0���� ũ�ų� ���� �̹� �湮���� ���� ���� ���
			pq.push({ cur_time + 1, cur_pos - 1 });  // {���� �ɸ� �ð� + 1, ���� ��ġ -1}
			visited[cur_pos - 1] = true;
		}
	}

	cout << result << '\n';


	return 0;
}