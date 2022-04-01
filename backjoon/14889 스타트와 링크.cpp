//���̵� : �ǹ�2
//���� : 09:25
//�� : 
#include <iostream>
#include <vector>

using namespace std;

int arr[21][21] = { 0 }; //�ɷ�ġ ���� �迭

int team_start[10] = { 0 }; //start �� ��� ��ȣ
int team_link[10] = { 0 }; //link �� ��� ��ȣ
int result = 1000; //��� 


bool is_available(int cur, int num) {
	for (int i = 0; i < cur; i++) { 
		if (team_start[i] >= num) { //������ ������ ����� ���� ����� ���ų� ������ Ż���Ѵ�. 
			//�� ������ ������ ���� ����� ���� ���̴� �ȵǰ� ������ ������ �̹� ã�� ����� ���̱� ���� 
			return false; //Ż��
		}
	}
	return true;
}

void DFS(int N, int cur) {
	if (N / 2 == cur) { //start �� ����� �� ���� ���
		int member[21] = { 0 };
		for (int i = 0; i < N / 2; i++) { //start ���� ���� ����� 1�� ó��
			member[team_start[i]] = 1;
		}
		int j = 0;
		for (int i = 1; i <= N; i++) { //link ���� ���� ����� 0���� ó���Ǿ� ������ �̸� �̿��Ͽ� team_link �迭�� ��� ��ȣ �Է�
			if (member[i] == 0) {
				team_link[j] = i;
				j++;
			}
		}
		//for (int i = 0; i < cur; i++) {
		//	cout << team_start[i] << " ";
		//}
		//cout << '\n';
		//for (int i = 0; i < cur; i++) {
		//	cout << team_link[i] << " ";
		//}
		//cout << '\n';
		int link_score = 0; //link �� �ɷ�ġ
		int start_score = 0; //start �� �ɷ�ġ
		for (int i = 0; i < N / 2; i++) { //2���� �迭�� ��ȸ �� �� link���� start���� �ɷ�ġ�� �ϳ��ϳ� ���
			for (int j = 0; j < N / 2; j++) {
				link_score += arr[team_link[i]][team_link[j]];
				start_score += arr[team_start[i]][team_start[j]];
			}
		}
		//cout << link_score << " " << start_score << '\n';
		if (result > abs(link_score - start_score)) { //�ɷ�ġ�� ���̸� ����ϰ� �� ���̰� ���� ���� ���� result�� ����
			result = abs(link_score - start_score);
		}
		return;
	}
	for (int i = cur + 1; i <= N; i++) { //1 2�� �����ϴ� �Ͱ� 2 1�� �����ϴ� ���� �����Ƿ� �����ϱ� ���� cur + 1���� ����
		team_start[cur] = i; //��� ��ȣ �ֱ�
		if (is_available(cur, i)) {
			DFS(N, cur + 1);
			team_start[cur] = 0; //�ٸ� ����� ���� ã�� ���� 0���� �ʱ�ȭ
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	
	DFS(N, 0);

	cout << result << '\n';
	return 0;
}