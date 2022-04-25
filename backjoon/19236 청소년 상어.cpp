//���̵� : ���2
//���� : 13:08
//�� :
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fish {
	int r;
	int c;
	int d;
	bool live;
};

int dr[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 }; //1���� ����
int dc[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int map[4][4]; //����� ��ȣ ����, 0 ��ĭ, -1 ���
int tmp_map[4][4]; //������� �� �����س���
Fish fish[17]; //����� ���� ���� �迭 //�ε����� ��ȣ
int score;

void print() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << map[r][c] << " ";// << map[r][c].d << " "; // << map[r][c].r << " " << map[r][c].c << " " << map[r][c].d << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void input() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			int n, d;
			cin >> n >> d;
			Fish tmp;
			tmp.r = r;
			tmp.c = c;
			tmp.d = d;
			tmp.live = true;
			fish[n] = tmp;
			map[r][c] = n;
		}
	}
}

//����� ������ �ٲٴ� �Լ�
void swap_fish(int a, int b) {
	int tmp_r = fish[a].r;
	int tmp_c = fish[a].c;
	fish[a].r = fish[b].r;
	fish[a].c = fish[b].c;
	fish[b].r = tmp_r;
	fish[b].c = tmp_c;
}

//����⸦ �����̴� �Լ�
void move_fish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].live == false) continue; //������ �н�
		int cr = fish[i].r;
		int cc = fish[i].c;
		int d = fish[i].d;
		d--; //���� �������� ���� �ڽ��� ������� �����ϱ� ���� -1
		for (int j = 0; j < 8; j++) {
			d++; //���� ������ +1�ϸ鼭 8���� ����
			if (d >= 9) d = 1; //d�� 9 �̻��̸� 1�� ��ȯ
			int nr = cr + dr[d];
			int nc = cc + dc[d];
			if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue; //�� �Ѿ�� �н�
			if (map[nr][nc] == -1) continue; //�� ������ �н�
			if (map[nr][nc] == 0) { //��ĭ�� ���
				map[nr][nc] = map[cr][cc]; //��ĭ���� �̵�
				map[cr][cc] = 0; //���� ĭ ��ĭ ó��
				//���� ����� ���� ������Ʈ
				fish[i].r = nr;
				fish[i].c = nc;
				fish[i].d = d;
				break;
			}
			else if (map[nr][nc] >= 1 && map[nr][nc] <= 16) { //����Ⱑ �ִ� ���
				int tmp = map[cr][cc]; //���� ����� ��ȣ �ӽ� ����
				map[cr][cc] = map[nr][nc]; //�� �ٲٱ�
				map[nr][nc] = tmp; //�� �ٲٱ�
				swap_fish(map[cr][cc], map[nr][nc]); //����� ���� ����
				fish[i].d = d; //���� �ٲٱ�
				break;
			}
		}
		//print();
	}
}

//���߿� ���� �ǵ����� ���� �ʱ� �� �����س��� �Լ�
//�迭�� �����ͷ� ������ ������ ���� ���簡 �ȴ�.
void copy_map_fish(int map[][4], int copy_map[][4], Fish fish[], Fish copy_fish[]) {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			copy_map[r][c] = map[r][c];
		}
	}

	for (int i = 1; i <= 16; i++) {
		copy_fish[i] = fish[i];
	}
}

//eat�� true�̸� ����⸦ �԰�
//eat�� false�̸� ����⸦ ��´�.
void eat_fish(int sr, int sc, int nr, int nc, int fish_num, bool eat) {
	if (eat == true) {
		fish[fish_num].live = false;//����� ����
		map[nr][nc] = -1; //�ʿ� ��� ǥ��
		map[sr][sc] = 0; //���� �� �ִ� �ڸ� ��ĭ ó��
	}
	else {
		fish[fish_num].live = true;//����� �츲
		map[nr][nc] = fish_num; //����� �ǵ���
		map[sr][sc] = -1; //��� ǥ��
	}
}

//��� ��ġ r, ��� ��ġ c, ��� ���� d, ���� ���� sum
void DFS(int sr, int sc, int sd, int sum) {
	//print();
	score = max(score, sum); //�ִ밪�� score�� ����
	//cout << score << '\n';
	int prev_map[4][4];
	Fish prev_fish[17];
	copy_map_fish(map, prev_map, fish, prev_fish);
	//print();
	move_fish();
	//print();
	for (int i = 1; i <= 3; i++) {
		int nr = sr + dr[sd] * i;
		int nc = sc + dc[sd] * i;
		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break; //���� �Ѿ ��� ����
		if (map[nr][nc] == 0) continue; //��ĭ�� ��� �н�
		
		int fish_num = map[nr][nc];
		int d = fish[fish_num].d;
		
			
		eat_fish(sr, sc, nr, nc, fish_num, true); //����� �Ծ��
		DFS(nr, nc, d, sum + fish_num); //���� ����� �� ���� 
		eat_fish(sr, sc, nr, nc, fish_num, false); //����� ���
			

		

	}
	copy_map_fish(prev_map, map, prev_fish, fish); //�ٸ� ����� ���� ���� �� �ǵ�������

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	bool stop;
	input();

	//�ʱ� ����� ��ġ�� score �ʱ�ȭ
	int sr = 0;
	int sc = 0;
	int fish_num = map[sr][sc];
	int d = fish[fish_num].d;
	fish[fish_num].live = false;
	map[sr][sc] = -1; //��� ǥ��
	score += fish_num; // ���� �߰�

	DFS(sr, sc, d, score);

	cout << score << '\n';

	return 0;
}