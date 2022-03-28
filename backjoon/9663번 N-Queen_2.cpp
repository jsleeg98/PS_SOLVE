//���̵� : ���5
//���� : 
//�� :
#include <iostream>

using namespace std;

int queen_col[15] = {0};
int cnt = 0;

//���� ���� �� ���� �������� ���� �Ǵ�
bool is_available(int current_row) {
	for (int row = 0; row < current_row; row++) {
		// ���� ���� �־ �ȵǰ�, �밢���� �־ �ȵȴ�.
		if ((queen_col[row] == queen_col[current_row]) || (current_row - row == abs(queen_col[current_row] - queen_col[row]))) {
			return false;
		}
	}
	return true;
}

void nqueen(int N, int current_row) {
	if (current_row == N) { //������ �� ���� ��� ����
		cnt++; //���� +1
		return;
	}
	for (int col = 0; col < N; col++) {
		queen_col[current_row] = col; //���� �࿡ �ĺ� ���� ���ƺ���
		if (is_available(current_row)) {
			nqueen(N, current_row + 1); //�����ϸ� DFS
		}//�ȵǸ� �ĺ� �� ��ü Ż��
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	nqueen(N, 0 );
	cout << cnt << '\n';

	return 0;
}