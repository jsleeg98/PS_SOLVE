//���� : 21:31
//�� : 22:50
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N;
struct pos {
	int r;
	int c;
};

vector<pos> person; //����� ��ġ ���� ����
vector<pair<pos, int>> stair; //����� ��ġ�� ���� ���� ����
int result = 987654321; //���� ���

void print(vector<int> v) {
	for (int i = 0; i < person.size(); i++) {
		cout << v[i] << " ";
	}
	cout << '\n';
}

//�Է�
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				person.push_back({ r, c });
			}
			else if (tmp >= 2) {
				stair.push_back({ {r, c}, tmp });
			}
		}
	}
}

void init() {
	person.clear(); //������ ���� ��� ��ġ ���� �ʱ�ȭ
	stair.clear(); //������ ���� ��� ��ġ ���� �ʱ�ȭ
	result = 987654321; //������ ���� ���� ��� �ʱ�ȭ
}

//���� ���� ����� ���� �ɸ��� �ð� ��� �Լ�
void solve(vector<int> v) {
	//print(v);
	//a�� b�� �� ��ܿ� �� ������ ����� �Ÿ� �߰� 
	//a�� ù��° ��� �̿���
	//b�� �ι�° ��� �̿���
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			pos tmp = person[i];
			int distance = abs(stair[0].first.r - tmp.r) + abs(stair[0].first.c - tmp.c);
			a.push_back(distance);
		}
		else {
			pos tmp = person[i];
			int distance = abs(stair[1].first.r - tmp.r) + abs(stair[1].first.c - tmp.c);
			b.push_back(distance);
		}
	}

	
	

	queue<int> q_a;
	queue<int> q_b;
	
	int time_a; //ù��° ��� �̿����� �ɸ��� �ð�
	int time_b; //�ι�° ��� �̿����� �ɸ��� �ð�

	
	if (a.size() == 0) {//ù��° ����� �̿��ϴ� ����� ���� ���
		time_a = 0; //�ɸ��� �ð� 0
	}
	else if (a.size() <= 3) { //ù��° ����� �̿��ϴ� ����� 3�� ������ ��� 
		sort(a.begin(), a.end()); //�����ϴ� �ð� �������� ���� 
		time_a = a[a.size() - 1] + stair[0].second; //������ ����� ����� �� ������ �ð��� ����� ��
	}
	else { //ù��° ����� �̿��ϴ� ����� 3�� �ʰ��� ���
		sort(a.begin(), a.end()); //�����ϴ� �ð� �������� ����
		//queue�� 3�� �ֱ�
		q_a.push(a[0]);
		q_a.push(a[1]);
		q_a.push(a[2]);
		int idx = 3; //ù��°��� �̿��ڸ� �����ϱ� ���� �ε���
		while (!q_a.empty()) { //queue�� �� ������ �ݺ�
			int cur_time = q_a.front() + stair[0].second; //�� �� ����� ������ �ð�
			q_a.pop();
			if (idx < a.size()) { //�̿��ڰ� ���� �ִ� ���
				if (cur_time > a[idx]) { //�� �� ����� ������ �ð����� ���� queue�� ���� ����� �����ð��� ���� ��� 
					a[idx] += cur_time - a[idx]; //queue�� ���� ����� ���� �ð��� �� �ջ���� ������ �ð����� ���̸�ŭ ������ ��Ų��.
					q_a.push(a[idx]); //queue�� �ִ´�.
				}
				else { //�� �� ����� ������ �ð����� ���� queue�� ���� ����� �����ð��� ���� ��� 
					q_a.push(a[idx]); //���� �ð� �������� queeu�� �ִ´�.
				}
				idx++; //���� ����� �����ϱ� ���� ++
			}
			time_a = cur_time; //���������� �����ϸ� �ᱹ time_a���� ù��° ����� �̿��ϴ� ������� �ɸ��� �ð��� ����ȴ�.
		}
	}
	
	//�ι�° ��ܵ� ù��° ��ܰ� �����ϰ� ����ȴ�.
	if (b.size() == 0) {
		time_b = 0;
	}
	else if (b.size() <= 3) {
		sort(b.begin(), b.end());
		time_b = b[b.size() - 1] + stair[1].second;
	}
	else {
		sort(b.begin(), b.end());
		q_b.push(b[0]);
		q_b.push(b[1]);
		q_b.push(b[2]);
		int idx = 3;
		while (!q_b.empty()) {
			int cur_time = q_b.front() + stair[1].second;
			q_b.pop();
			if (idx < b.size()) {
				if (cur_time > b[idx]) {
					b[idx] += cur_time - b[idx];
					q_b.push(b[idx]);
				}
				else {
					q_b.push(b[idx]);
				}
				idx++;
			}
			time_b = cur_time;
		}
	}
	//cout << time_a << " " << time_b << '\n';
	int result_time = max(time_a, time_b); //ù��° ��ܰ� �ι�° ��ܿ� �ɸ��� �ð� �� ���� �ɸ��� ���� ���� �ɸ��� �ð��̴�.

	//������ �ش��� ��� ����� ���� �ɸ��� �ð� �� �ּ� ���̴�.
	result = min(result_time, result);
	


}

//��� ����� �� �ľ��� ���� DFS
void DFS(vector<int> v, int cur, int p) {
	if (cur == p) { //��� ����� ��츦 ������ ���
		solve(v); //�ɸ��� �ð� ���
		return; //����
	}
	//0�� ù��° ���, 1�� �ι�° ���
	for (int i = 0; i <= 1; i++) {
		v.push_back(i); 
		DFS(v, cur + 1, p); //���� ����� ����� �� ã�� ����
		v.pop_back(); //�ٸ� ����� �� ã�� ����
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
		vector<int> v;
		DFS(v, 0, person.size());
		cout << "#" << test_case << " " << result + 1 << '\n';

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}