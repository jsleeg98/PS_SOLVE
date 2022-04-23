//���� : 16:53
//�� : 17:55
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int N; //������ ����
int K; //����
int cut;
deque<char> number;
vector<long long int> result;

void init() {
	number.clear();
	result.clear();
}

//���ڸ� �������� �ٲٴ� �Լ�
int change_10(char a) {
	int tmp = (int)a;
	if (tmp >= 65) {
		tmp -= 65; //���ĺ� A�� 65 �̹Ƿ� 
		tmp += 10; //A���� 10�̹Ƿ� +10
	}
	else { //������ ���� �̹Ƿ� -48
		tmp -= 48;
	}
	return tmp;
}

void get_number() {
	for (int i = 0; i < number.size(); i += cut) {
		long long int tmp_result = 0;
		for (int j = 0; j < cut; j++) {
			char tmp = number[i + j];
			int num = change_10(tmp);
			//cout << num << '\n';
			tmp_result += num * pow(16, cut - 1 - j);
		}
		result.push_back(tmp_result);
	}

	//cout << result.size() << '\n';
}

void rotate() {
	char tmp;
	tmp = number.back();
	number.pop_back();
	number.push_front(tmp);
}

long long int final_result() {
	long long int final_result_num;
	int cnt = 1;
	long long int before = result[0];
	if (K == 1) { //1�� ���� ó��
		return result[0];
	}
	for (int i = 1; i < result.size(); i++) {
		//cout << result[i] << '\n';
		if (before != result[i]) { //�ߺ� ó��
			before = result[i];
			cnt++;
		}
		if (cnt == K) { // �ش� ��� �� ��� ����
			final_result_num = result[i];
			break;
		}
	}
	return final_result_num;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;

	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> K;
		cut = N / 4;
		string tmp;
		cin >> tmp;
		for (int i = 0; i < tmp.length(); i++) {
			number.push_back(tmp[i]);
		}
		get_number();
		for (int i = 0; i < cut - 1; i++) {
			rotate();
			get_number();
		}

		sort(result.begin(), result.end());
		reverse(result.begin(), result.end());
		
		int ans = final_result();
		cout << "#" << test_case << " " << ans << '\n';
	
		




	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}