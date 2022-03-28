//���̵� : ���5
//���� : 14:09
//�� : 17:30
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct line { //����ü ����
	int start; //���۹�ȣ
	int end; //�� ��ȣ
	int DP = 0; //�� ��ȣ�� �����ϴ� ��� ���� ���� �ִ� ���� ���� DP
}line;

bool compare(line a, line b) { //start�� �������� �������� ������ ���� ��
	return a.start < b.start;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<line> line_v;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		line tmp_line;
		cin >> tmp_line.start >> tmp_line.end;
		line_v.push_back(tmp_line);
	}

	//���� ��ȣ�� �������� ����
	sort(line_v.begin(), line_v.end(), compare);


	//for (int i = 0; i < line_v.size(); i++) {
	//	cout << line_v[i].start << " " << line_v[i].end << '\n';
	//}

	//�� ��ȣ�� �������� �ִ� ���� ���� ���� ã��
	for (int i = 0; i < line_v.size(); i++) {
		int tmp_max = 0;
		for (int j = 0; j < i; j++) {
			if (line_v[j].end < line_v[i].end) {
				if (tmp_max < line_v[j].DP) {
					tmp_max = line_v[j].DP;
				}
			}
		}
		line_v[i].DP = tmp_max + 1;
	}
	
	//�ִ� ���� ã��
	int result = 0;
	for (int i = 0; i < line_v.size(); i++) {
		if (result < line_v[i].DP) {
			result = line_v[i].DP;
		}
	}

	//����� ���� �� �������� �ִ� �� ������ ���� �����ϴ� ���� ������ ���´�.
	cout << line_v.size() - result << '\n';

	return 0;
}