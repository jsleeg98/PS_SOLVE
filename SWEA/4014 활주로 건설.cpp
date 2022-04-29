//���� : 20:20
//�� :
#include<iostream>

using namespace std;

int N, X;
pair<int, bool> map[20][20]; //����, �ٸ��� ���� ����

//�Է�
void input() {
	cin >> N >> X;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int tmp;
			cin >> tmp;
			map[r][c].first = tmp;
			map[r][c].second = false; //�ٸ��� �ȼ��� ������ �ʱ�ȭ
		}
	}
}


int solve() {
	int cnt = 0;
	for (int r = 0; r < N; r++) { //�� �������� ó��
		bool flag = true; //flag�� ���� ���� �������� ���� Ȯ�� 
		for (int i = 0; i < N - 1; i++) {
			int a = map[r][i].first;
			int b = map[r][i + 1].first;
			if (b - a == -1) { //���� 1 �������� ���
				map[r][i + 1].second = true; //�ٸ� ���� ǥ��
				for (int j = 1; j < X; j++) { //�ڷ� �ٸ� ���̸�ŭ Ȯ��
					i++;
					if (i + 1 >= N) { //���� �Ѿ�� ����
						flag = false;
						break;
					}
					if (map[r][i+1].first != b) { //���� ���̰� �ٸ��� ���� ���� �޶����� ����
						flag = false;
						break;
					}
					map[r][i + 1].second = true; //�ٸ� ���� ǥ��
				}
			}
			else if (b - a == 1) { //���� 1�������� ���
				map[r][i].second = true; //�ٸ� ���� ǥ��
				for (int j = 1; j < X; j++) { //�������� Ȯ��
					if (i - j < 0) { //���� �Ѿ�� ����
						flag = false;
						break;
					}
					if (a != map[r][i - j].first) { // �ٸ��� ���� ���� ���̰� �޶����� ����
						flag = false;
						break;
					}
					if (map[r][i - j].second == true) { //�ٸ��� �̹� �������� ����
						flag = false;
						break;
					}
					map[r][i - j].second = true; //�ٸ� ���� ǥ��
				}
			}
			else if(abs(b-a) > 1) { //���� ���̰� 1���� ũ�� ���̳��� ����
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	//�� �������� Ȯ���ϱ� ���� �ٸ� ���� ǥ�ø� false�� �ʱ�ȭ
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			map[r][c].second = false;
		}
	}

	//�� ���ؿ��� ���������� �ٲ㼭 �ǽ�
	for (int c = 0; c < N; c++) {
		bool flag = true;
		for (int i = 0; i < N-1; i++) {
			int a = map[i][c].first;
			int b = map[i+1][c].first;
			if (b-a == -1) {
				map[i + 1][c].second = true;
				for (int j = 1; j < X; j++) {
					i++;
					if (i + 1 >= N) {
						flag = false;
						break;
					}
					if (map[i + 1][c].first != b) {
						flag = false;
					}
					map[i + 1][c].second = true;
				}
			}
			else if (b - a == 1) {
				map[i][c].second = true;
				for (int j = 1; j < X; j++) {
					if (i - j < 0) {
						flag = false;
						break;
					}
					if (a != map[i - j][c].first) {
						flag = false;
						break;
					}
					if (map[i - j][c].second == true) {
						flag = false;
						break;
					}
					map[i - j][c].second = true;
				}
			}
			else if(abs(b-a) > 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	return cnt;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		input();
		int result;
		result = solve();
		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}