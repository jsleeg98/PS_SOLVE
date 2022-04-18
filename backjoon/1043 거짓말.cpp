//���̵� : ���4
//���� : 11:38
//�� : 12:09
#include <iostream>
#include <vector>

using namespace std;

int parent[51]; //�θ� ��� ����

//�θ� ��� ���(�����)
int getParent(int n) {
	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = getParent(parent[n]);
	}
}

//���� �θ����� Ȯ��
int checkParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}

//��� ��ȣ�� ���� ������ �θ� ��ġ��
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (!checkParent(a, b)) {
		if (a < b) {
			parent[b] = a;
		}
		else {
			parent[a] = b;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v[50]; //��Ƽ ������ ���� ����
	int know[51] = { 0 }; //�������� �ƴ� ��� ��ȣ
	int N, M;
	cin >> N >> M;
	int T; //�������� �ƴ� ��� ��
	cin >> T;
	//�������� �ƴ� ��� �Է�
	for (int i = 0; i < T; i++) {
		cin >> know[i];
	}
	//��Ƽ ������ �Է�
	for (int i = 0; i < M; i++) {
		int people_num; //��Ƽ ������ ��
		cin >> people_num;
		for (int j = 0; j < people_num; j++) {
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp); //���Ϳ� push
		}
	}

	//for (int i = 0; i < M; i++) {
	//	for (int j = 0; j < v[i].size(); j++) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	//�θ� ��� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	//���� ��Ƽ �����ڵ��� �ϳ��� �������� ��ġ��
	for (int i = 0; i < M; i++) {
		if (v[i].size() == 1) { //�����ڰ� �Ѹ��̸� �н�
			continue;
		}
		else { //�����ڰ� 2�� �̻��̸�
			int num = v[i][0]; //ó���� ������ ��ȣ�� ���� ���� ��ȣ��� �����ϰ�
			for (int j = 1; j < v[i].size(); j++) {//������ ��Ƽ ������ ��ħ
				unionParent(num, v[i][j]);
			}
		}
	}

	//������� �����ϸ� parent �迭���� ���� ��Ƽ �������̰� �Ѹ��̶� ��ġ�� ����� ������ ��� ���� ��Ƽ �����ڷ� ó���Ͽ�
	//������ �ִ�.

	//������ �� �� �ִ� ��Ƽ ���� ����
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool fail = false;
		int p = getParent(v[i][0]); //�� ��Ƽ�� �� ��ȣ�� Ȯ���ϸ� �ȴ�. �� ������ �̹� �ϳ��� �������� ó���� �ξ��� �Ǿ��� ���� ���� ��ȣ�̱� �����̴�.
		for (int j = 0; j < T; j++) {
			//���⼭ getParent(know[j])�� ���� �ʰ� know[j]���� �Ѵٸ� ���� 7���� ���� �������� �ƴ� ����� ��� ��ȣ�� ���� ���� ���� ��쿡 Ž���� �Ұ����ϴ�!!!!!
			if (getParent(know[j]) == p) { //�������� �ƴ� ����� �θ� ��带 ã�� �� ���� ��Ƽ ������ �θ� ��带 ���ؼ� ���ٸ�
				fail = true; //�������� �� �� ���� ó��
				break;
			}
		}
		if (!fail) { //�������� �� �� �ִ� ��쿡�� +1
			cnt++;
		}
	}

	//������ �� �� �ִ� ��Ƽ �� ���
	cout << cnt << '\n';

	return 0;
}