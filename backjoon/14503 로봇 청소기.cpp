//���̵� : ���5
//���� : 21:44
//�� : 23:11
#include <iostream>

using namespace std;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };//��, ��, ��, ��
int map[50][50];
int N, M;

//���� ����
int change_dir(int dir_num) {
	dir_num -= 1;
	if (dir_num == -1) {
		dir_num = 3;
	}
	return dir_num;
}

//��������� �����Ϸ��� ������ �Ұ����ϴ�!!!!
int clean(int r, int c, int cnt, int dir_num, int result) {
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << '\n';
	//}
	cout << '\n';
	if (cnt == 4) { //�� ������ �� �� ���
		int back_num = change_dir(dir_num);
		back_num = change_dir(back_num); //�������� �ι� ���� ���� ����
		int back_r = r + dir[back_num][0];
		int back_c = c + dir[back_num][1];
		if (map[back_r][back_c] != 1) {
			cout << "back" << '\n';
			clean(back_r, back_c, 0, dir_num, result); //������ �״�� �����Ͽ� �ѹ��� ��ȸ�� �� �ش�.
			//���� return�� �Ͽ��� �� �κ����� ���ƿͼ� cnt == 4�� ���·� ��� ����Ǿ� ���� �ݺ��ȴ�.
			//���� ��������� �����ϸ� �ذ� �Ұ���!!!!!!!
		}
		else {
			//for (int i = 0; i < N; i++) {
			//	for (int j = 0; j < M; j++) {
			//		cout << map[i][j] << " ";
			//	}
			//	cout << '\n';
			//}
			return result;
		}
	}
	dir_num = change_dir(dir_num); //���� ���⿡�� ���� ����
	int next_r = r + dir[dir_num][0]; //���� ���� ��
	int next_c = c + dir[dir_num][1]; //���� ���� ��
	if (map[next_r][next_c] == 0) { //���� ������ ��ĭ�̶��
		map[next_r][next_c] = 2; //���� ��ġ û�� ó��
		clean(next_r, next_c, 0, dir_num, result+1); //û�ұ� �����̰� ���� û�� ����
	}
	else { //��ĭ�� �ƴ� ���
		clean(r, c, cnt + 1, dir_num, result); //ī��Ʈ �ø���.
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;
	int cur_r, cur_c;
	int dir_num;
	cin >> cur_r >> cur_c >> dir_num;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
		}
	}


	int result = 0;
	while (1) {
		if (map[cur_r][cur_c] == 0) {
			map[cur_r][cur_c] = 2; //û�� ó��
			result++; //û���� ���� +1
		}

		bool check_4 = true;
		for (int i = 0; i < 4; i++) {
			dir_num = (dir_num + 3) % 4; //���� ����
			int next_r = cur_r + dir[dir_num][0];
			int next_c = cur_c + dir[dir_num][1];
			if (map[next_r][next_c] == 0) { //��ĭ�̶��
				cur_r = next_r;
				cur_c = next_c;
				check_4 = false; //4 ���� �߿� ��ĭ�� �ִ� ��� false�� ǥ��
				break; //���� ��ġ�� �̵�
			}
		}

		//4���� ��� ��ĭ�� �ƴ� ���
		if (check_4) {
			int back_dir = (dir_num + 2) % 4; // ���� ����
			int back_r = cur_r + dir[back_dir][0];
			int back_c = cur_c + dir[back_dir][1];
			if (map[back_r][back_c] == 1) { //�����ߴ��� �ڰ� ���� ���
				break; // ����
			}
			else { //���� �ƴ� ��� ���� �̵�
				cur_r = back_r;
				cur_c = back_c;
			}
		}
	}

	//û���� ���� ���
	cout << result << '\n';

	return 0;
}