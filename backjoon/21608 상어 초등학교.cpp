//���̵� : �ǹ�1
//���� : 20:36
//�� : 22:38
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int chair[22][22]; //�����¿� padding 1
int N; 

//r, c ��ġ���� ��ĭ�� ���� �����ϴ� ��ȣ �� ���� ����ü
struct info {
	int vacant = 0;
	int like = 0;
	int r;
	int c;
};


//r, c ��ġ���� ������ ���� ��ĭ�� �ִ� ���� ��ȯ �Լ�
int vacant_chair_num(int r, int c) {
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int vacant = 0;
	for (int i = 0; i < 4; i++) {
		int rr = r + dir[i][0];
		int cc = c + dir[i][1];
		if (rr == 0 || rr == N + 1 || cc == 0 || cc == N + 1) {
			continue; //�׵θ��� �н�
		}
		if (chair[rr][cc] == 0) {
			vacant++; //��ĭ +1
		}
	}
	return vacant;
}

//r, c ��ġ���� ������ ���� �����ϴ� ��ȣ�� ���� ��ȯ �Լ�
int like_chair_num(int r, int c, vector<int> like_num) {
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int like = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			int rr = r + dir[i][0];
			int cc = c + dir[i][1];
			if (chair[rr][cc] == like_num[j]) {
				like++; //��ĭ +1
			}
		}
	}
	
	return like;
}

//�� �켱����
//1. �ֺ��� �����ϴ� ��� �� ���� ��
//2. �ֺ��� ��ĭ�� ���� ��
//3. �� ��ȣ�� ���� ��
//4. �� ��ȣ�� ���� ��
bool compare(info a, info b) {
	if (a.like > b.like) {
		return true;
	}
	else if (a.like == b.like) {
		if (a.vacant > b.vacant) {
			return true;
		}
		else if (a.vacant == b.vacant) {
			if (a.r < b.r) {
				return true;
			}
			else if (a.r == b.r) {
				if (a.c < b.c) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> v_like_info[401];
	int result = 0;

	cin >> N;
	for (int i = 0; i < N*N; i++) {
		int num;
		cin >> num;
		
		vector<int> like_num; //�����ϴ� ��� ���� �迭
		for (int i = 0; i < 4; i++) {
			int tmp;
			cin >> tmp;
			like_num.push_back(tmp);
		}

		v_like_info[num].push_back(like_num); //num �ε����� �����ϴ� ��� ���� push

		vector<info> v; //���� num ���� ���� info ���� ����
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (chair[r][c] == 0) { //���� ��ġ�� ��ĭ�� ��쿡�� ����
					int like = like_chair_num(r, c, like_num); //�ֺ��� �����ϴ� ��� �� ����
					int vacant = vacant_chair_num(r, c); //�ֺ��� ��ĭ �� ����
					info tmp;
					tmp.r = r; //���� �� 
					tmp.c = c; //���� ��
					tmp.like = like;
					tmp.vacant = vacant;
					v.push_back(tmp); //���Ϳ� push
				}
				
			}
		}
		sort(v.begin(), v.end(), compare); //�񱳸� ���� �켱������ ���� ����
		chair[v[0].r][v[0].c] = num; //�Ǿտ� �ִ� ��ġ�� ���� num �ֱ�


		//�߰� ��� ���
		/*for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				cout << chair[r][c] << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
	}

	//������ ����
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 1) {
				result += 1;
			}
			else if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 2) {
				result += 10;
			}
			else if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 3) {
				result += 100;
			}
			else if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 4) {
				result += 1000;
			}
		}
	}

	//������ ���
	cout << result << '\n';
	

	return 0;
}