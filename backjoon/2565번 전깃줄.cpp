//난이도 : 골드5
//시작 : 14:09
//끝 : 17:30
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct line { //구조체 선언
	int start; //시작번호
	int end; //끝 번호
	int DP = 0; //끝 번호를 포함하는 경우 증가 수열 최대 길이 저장 DP
}line;

bool compare(line a, line b) { //start를 기준으로 오름차순 정렬을 위한 비교
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

	//시작 번호를 기준으로 정렬
	sort(line_v.begin(), line_v.end(), compare);


	//for (int i = 0; i < line_v.size(); i++) {
	//	cout << line_v[i].start << " " << line_v[i].end << '\n';
	//}

	//끝 번호를 기준으로 최대 증가 수열 길이 찾기
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
	
	//최대 길이 찾기
	int result = 0;
	for (int i = 0; i < line_v.size(); i++) {
		if (result < line_v[i].DP) {
			result = line_v[i].DP;
		}
	}

	//출력은 원래 줄 개수에서 최대 줄 개수를 빼면 빼야하는 줄의 개수가 나온다.
	cout << line_v.size() - result << '\n';

	return 0;
}