#include <iostream>
#include <vector>

using namespace std;

int N;
int map[20][20];
//�밢�� �̵�
int dr[] = { 1, 1, -1, -1 }; 
int dc[] = { -1, 1, 1, -1 };
int final_result = 0;

void init() {
	final_result = 0; //���� �� �ʱ�ȭ
}

//�Է�
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}
}

//������ �簢���� �׸��鼭 ����Ʈ�� ���� �� �ִ��� Ȯ���ϰ� ���� ���� �Լ�
void eat(int r , int c, int d1, int d2) {
	vector<int> food;
	food.push_back(map[r][c]); //�� ���� ����Ʈ �߰�
	int cr;
	int cc;
	int sr = r; //���� ��ġ ����
	int sc = c; //���� ��ġ ����
	for (int i = 1; i <= d1; i++) { //�簢�� �Ѻ� �׸���
		int nr = sr + dr[0] * i;
		int nc = sc + dc[0] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	sr = cr; //���� ��ġ ����
	sc = cc; //���� ��ġ ����

	for (int i = 1; i <= d2; i++) { //�簢�� �Ѻ� �׸���
		int nr = sr + dr[1] * i;
		int nc = sc + dc[1] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	sr = cr; //������ġ ����
	sc = cc; //������ġ ����

	for (int i = 1; i <= d1; i++) { //�簢�� �Ѻ� �׸���
		int nr = sr + dr[2] * i;
		int nc = sc + dc[2] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	sr = cr; //������ġ ����
	sc = cc; //������ġ ����

	for (int i = 1; i < d2; i++) { //�簢�� �Ѻ� �׸��� �̶��� �ٽ� ���ƿ��� ��ġ�� ���� ���� <�� ���
		int nr = sr + dr[3] * i;
		int nc = sc + dc[3] * i;
		food.push_back(map[nr][nc]);
		cr = nr;
		cc = nc;
	}

	//����Ʈ ������ ��ġ���� Ȯ��
	bool stop = false;
	int num[101] = { 0 };
	for (int i = 0; i < food.size(); i++) {
		if (num[food[i]] == 1) { //��ġ�� ���
			stop = true; //���� ǥ��
			break;//����
		}
		num[food[i]]++;
	}

	//int result = 0;
	if (stop == false) { //������ ��ġ�� �ʴ� ���
		int result = food.size();
		final_result = max(final_result, result); //���� �� ����
	}

	

}

//������ ����� �� Ž��
void solve() {
	for (int r = 0; r < N; r++) {
		for (int c = 1; c < N - 1; c++) {
			for (int d1 = 1; d1 <= N - 2; d1++) {
				if (c - d1 < 0) break; //d1�� �ʹ� ū ��� �н�
				for (int d2 = 1; d2 < N - r - d1; d2++) {
					if (c + d2 >= N) break; //d2�� �ʹ� ū ��� �н�
					if (r + d2 >= N) break; //d2�� �ʹ� ū ��� �н�
					if (c - d1 + d2 >= N) continue; //�н� 
					if (r + d1 + d2 >= N) continue; //�н�
					//cout << r << " " << c << " " << d1 << " " << d2 << '\n';
					eat(r, c, d1, d2); //����Ʈ Ȯ��
					
					//cout << final_result << '\n';
				}
			}
		}
	}
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
		init();
		input();
		solve();
		if (final_result != 0) { //����Ʈ�� ���� �� �ִ� ���
			cout << "#" << test_case << " " << final_result << '\n';
		}
		else { //����Ʈ�� ���� �� ���� ���
			cout << "#" << test_case << " " << -1 << '\n';
		}
		

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}