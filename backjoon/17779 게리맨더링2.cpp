//���̵� : ���4
//���� : 20:58 - 22:12
//�� : 20:30 - 21:45
#include <iostream>
#include <algorithm>

using namespace std;

int map[21][21];
int label[21][21];
int N;
int result = 987654321;

void print() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << label[r][c] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
		}
	}
}

//���� �󺧸� �ϴ� �Լ�
void labeling(int x, int y, int d1, int d2) {
	//�켱 ��� ������ 5�� �������� �󺧸� �Ѵ�.
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			label[r][c] = 5;
		}
	}

	//1�� ����
	int sub = 0;
	for (int r = 1; r < x + d1; r++) {
		if (r >= x) sub++; //���� x �̻��� �� ���� ������ �ϳ��� ���δ�
		for (int c = 1; c <= y - sub; c++) {
			label[r][c] = 1;
		}
	}

	//2�� ����
	sub = 0;
	for (int r = 1; r <= x + d2; r++) {
		if (r > x) sub++; //���� x ���� Ŭ �� ���� ������ �ϳ��� ���δ�
		for (int c = y + 1 + sub; c <= N; c++) {
			label[r][c] = 2;
		}
	}

	//3�� ����
	sub = 0;
	for (int r = N; r >= x + d1; r--) {
		if (r < x + d1 + d2) sub++; //���� x + d1 + d2 ���� ���� �� ���� ������ �ϳ��� ���δ�
		for (int c = 1; c < y - d1 + d2 - sub; c++) {
			label[r][c] = 3;
		}
	}

	//4�� ����
	sub = 0;
	for (int r = N; r > x + d2; r--) {
		if (r <= x + d1 + d2) sub++; //���� x + d1 + d2 ������ �� ���� ������ �ϳ��� ���δ�
		for (int c = y - d1 + d2 + sub; c <= N; c++) {
			label[r][c] = 4;
		}
	}
}

void calc() {
	int sum_people[6] = { 0 };
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			sum_people[label[r][c]] += map[r][c]; //�󺧿� �ش��ϴ� ���� �� ����
		}
	}
	sort(sum_people + 1, sum_people + 6); // 1�� �������� 5�� �������� �α��� ����
	int diff = sum_people[5] - sum_people[1]; //�ִ� - �ּ�
	//cout << diff << '\n';
	result = min(result, diff); //������ �ּҰ��� ����
	
}

void solve() {
	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= N - 2; d1++) {
				for (int d2 = 1; d2 <= N - 2; d2++) {
					if (x + d1 > N || y - d1 < 1) continue;
					if (x + d1 + d2 > N || y - d1 + d2 > N) continue;
					if (x + d2 > N || y + d2 > N) continue;
					labeling(x, y, d1, d2);
					//cout << x << " " << y << " " << d1 << " " << d2 << '\n';
					//print();
					calc();
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	
	cout << result << '\n';

	return 0;
}