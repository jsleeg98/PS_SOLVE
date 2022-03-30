//���̵� : �ǹ�4
//���� : 23:24
//�� : 01:21
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int arr_1[500000] = { 0 };
vector<pair<int, int>> arr_2;

//���� Ž������ vector�� Ž���Ͽ� first���� ���ڰ� second���� ������ ������ ����ִ�.
int BS(int start, int end, int num) {
	if (end - start == 1 && arr_2[start].first == num) { //ã�� ���
		return arr_2[start].second; //�ش� ������ ���� ���
	}
	if (end - start == 1 && arr_2[start].first != num) { //�� ã�� ���
		return 0; //0�� ���
	}
	if (end - start == 0) { //��ã�� ���
		return 0; //0�� ���
	}
	int middle = (start + end) / 2; //�߰� �ε��� ���ϱ�
	if (arr_2[middle].first == num) { //ã�� ���
		return arr_2[middle].second; //�ش� ��ȣ�� ���� ���
	}
	else { //��ã�� ���
		if (num < arr_2[middle].first) { //ã������ ���� �߰� ������ ���� ���
			return BS(start, middle, num); //���ʿ��� BS
		}
		else if (num > arr_2[middle].first) { //ã������ ���� �߰� ������ ū ���
			return BS(middle + 1, end, num); //�����ʿ��� BS
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) { //�Է�
		cin >> arr_1[i];
	}
	sort(arr_1, arr_1 + N); //�������� ����
	//���ĵ� �迭���� ���� ������ ������ ���� vector �迭�� ����
	for (int i = 0; i < N; i++) {
		int num = arr_1[i];
		int count = 1;
		int j = 1;
		while (1) {
			if (i + j < N) { //�迭�� ũ�⸦ ���� ���� ���
				if (arr_1[i + j] == num) { //���� ���ڰ� ������
					count++; //������ ���� +1
					j++; //���� �ε���
				} 
				else { //���� ���ڰ� �ٸ� ���
					arr_2.push_back(make_pair(num, count)); //��������� ������ ������ ���ڸ� vector�� ����
					break; //����
				}
			}
			else { //�迭�� ũ�⸦ ���� ���
				arr_2.push_back(make_pair(num, count)); //��������� ������ ������ ���ڸ� vector�� ����
				break;
			}
		}
		i = i + j - 1; //���� ���ڸ� ���� ���� ����
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << BS(0, arr_2.size(), tmp) << " "; //���Ϳ��� ���� Ž�� ����
	}
	cout << '\n';

	return 0;
}