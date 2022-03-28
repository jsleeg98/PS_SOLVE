//���̵� : �ǹ�1
//���� : 18:10
//�� :
#include <iostream>
#include <vector>

using namespace std;

//MBTI�� ���ڷ� �ٲٴ� �Լ�
vector<int> change_num(string tmp) {
	vector<int> num_mbti;
	if (tmp[0] == 'E') {
		num_mbti.push_back(1);
	}
	else {
		num_mbti.push_back(2);
	}
	if (tmp[1] == 'N') {
		num_mbti.push_back(1);
	}
	else {
		num_mbti.push_back(2);
	}
	if (tmp[2] == 'F') {
		num_mbti.push_back(1);
	}
	else {
		num_mbti.push_back(2);
	}
	if (tmp[3] == 'J') {
		num_mbti.push_back(1);
	}
	else {
		num_mbti.push_back(2);
	}

	return num_mbti;
}

//3���� MBTI�� �Ÿ��� ����ϴ� �Լ�
int get_distance(vector<vector<int>> mbti_3) {
	int distance = 0;
	for (int i = 0; i < 4; i++) {
		distance += abs(mbti_3[0][i] - mbti_3[1][i]);
	}
	for (int i = 0; i < 4; i++) {
		distance += abs(mbti_3[1][i] - mbti_3[2][i]);
	}
	for (int i = 0; i < 4; i++) {
		distance += abs(mbti_3[0][i] - mbti_3[2][i]);
	}
	return distance;
}

// ����� ���� ���� �Ÿ� �����ϴ� �Լ�
int solve(vector<vector<int>> mbti) {
	int min_distance = 100;
	for (int i = 0; i < mbti.size() - 2; i++) {
		for (int j = i + 1; j < mbti.size() - 1; j++) {
			for (int k = j + 1; k < mbti.size(); k++) {
				vector<vector<int>> mbti_3;
				mbti_3.push_back(mbti[i]);
				mbti_3.push_back(mbti[j]);
				mbti_3.push_back(mbti[k]);
				int distance = get_distance(mbti_3);
				if (min_distance > distance) { //�ּҰ� ã��
					min_distance = distance;
				}
			}
		}
	}
	return min_distance;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<vector<int>> mbti;
		for (int j = 0; j < N; j++) { //MBTI �Է� �ޱ�
			string tmp;
			cin >> tmp;
			mbti.push_back(change_num(tmp));
		}
		if (N >= 33) { //33���̻��� ��� �ݵ�� �Ÿ��� 0�̴�. MBTI�� ������ 16���̱� ������ �ִ��� �ְ� �Ϸ��� �ص� �ߺ��Ǵ� 3���� �����ϱ� �����̴�.
			cout << 0 << '\n';
		}
		else { //32�� ������ ��� �ּ� �Ÿ� ����
			int min_distance = solve(mbti);
			cout << min_distance << '\n';
		}
		
	}

	return 0;
}