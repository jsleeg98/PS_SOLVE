//난이도 : 실버1
//시작 : 18:10
//끝 :
#include <iostream>
#include <vector>

using namespace std;

//MBTI를 숫자로 바꾸는 함수
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

//3개의 MBTI의 거리를 출력하는 함수
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

// 경우의 수에 따라 거리 측정하는 함수
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
				if (min_distance > distance) { //최소값 찾기
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
		for (int j = 0; j < N; j++) { //MBTI 입력 받기
			string tmp;
			cin >> tmp;
			mbti.push_back(change_num(tmp));
		}
		if (N >= 33) { //33개이상인 경우 반드시 거리가 0이다. MBTI의 종류가 16개이기 때문에 최대한 멀게 하려고 해도 중복되는 3개가 존재하기 때문이다.
			cout << 0 << '\n';
		}
		else { //32개 이하인 경우 최소 거리 측정
			int min_distance = solve(mbti);
			cout << min_distance << '\n';
		}
		
	}

	return 0;
}