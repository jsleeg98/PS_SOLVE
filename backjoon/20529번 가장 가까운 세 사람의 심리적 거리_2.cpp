//난이도 : 실버1
//시작 : 18:10
//끝 : 
#include <iostream>
#include <vector>

using namespace std;

//두 MBTI의 거리를 출력하는 함수
int get_distance(string a, string b) {
	int distance = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) { //문자가 다를경우 거리 +1
			distance += 1;
		}
	}
	return distance;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<string> str;
		int N;
		cin >> N;
		for (int j = 0; j < N; j++) { //MBTI를 입력 받는다.
			string tmp;
			cin >> tmp;
			str.push_back(tmp);
		}
		if (N > 32) { //받은 MBTI개수가 32개를 넘는 경우 아무리 거리를 멀리 하려고 해도 MBTI는 16 종류이기 때문에 반드시 3개가 중복되는 것이 발생한다.
			//이 때는 거리가 무조건 0이기 때문에 거리를 측정할 필요가 없다.
			cout << 0 << '\n';
		}
		else { //32개 이하이면 다양한 거리가 나올 수 있기 때문에 최소 거리를 직접 계산한다.
			int min_distance = 100;
			for (int i = 0; i < N - 2; i++) {
				for (int j = i + 1; j < N - 1; j++) {
					for (int k = j + 1; k < N; k++) { //최소 값 찾기를 한다.
						min_distance = min(min_distance, get_distance(str[i], str[j]) + get_distance(str[j], str[k]) + get_distance(str[i], str[k]));
					}
				}
			}
			cout << min_distance << '\n'; //최소 거리 출력
		}

	}

	return 0;
}