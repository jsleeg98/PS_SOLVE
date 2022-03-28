//���̵� : ���5
//���� : 11:00
//�� : 11:57
#include <iostream>

using namespace std;

// �κ� LCS�� �����ϱ����� DP
int LCS_DP[1001][1001] = { 0 };

//LCS�� Long Common Sequence�� ���� �� ���� �κ��̴�. 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//���ڿ��� �ε��� 1���� �� �� �ֵ��� �� ���� ��ĭ���� ä���ش�.
	string a = " "; 
	string b = " ";
	
	string tmp;
	cin >> tmp;
	a += tmp;
	cin >> tmp;
	b += tmp;

	//2���� �迭�� LCS_DP�� ����� �����ϸ�
	//���ڰ� ��ġ�� ��� ���� �� �밢�� ������ +1 �� ��,
	//���ڰ� ����ġ�� ��� ��, ������ �� �� ū ���� ���� �����Ѵ�.
	for (int i = 1; i < b.length(); i++) {
		for (int j = 1; j < a.length(); j++) {
			if (b[i] == a[j]) {
				LCS_DP[i][j] = LCS_DP[i - 1][j - 1] + 1;
			}
			else {
				LCS_DP[i][j] = max(LCS_DP[i - 1][j], LCS_DP[i][j - 1]);
			}
		}
	}

	//LCS_DP ���� ������ �Ʒ��� �ִ� ���� LCS ���̴�.
	cout << LCS_DP[b.length() - 1][a.length() - 1] << '\n';

	return 0;
}