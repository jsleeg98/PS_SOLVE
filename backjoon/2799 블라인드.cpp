//난이도 : 실버4
//시작 : 
//끝 :
#include <iostream>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//인덱스 1부터 사용해야하는 이유는 맨처음에 #이 나오기 때문에 result가 계산되어버리기 때문이다.
	int result[6] = { 0 }; //인덱스 1부터 사용하며 타입의 총 개수 저장

	int M, N;
	cin >> M >> N;

	int type[101] = { 0 }; //인덱스 1부터 사용
	for (int i = 0; i < 1 + 5 * M; i++) {
		string tmp;
		cin >> tmp;
		if (tmp[1] == '#') { //다음 층을 만나면 초기화
			for (int i = 1; i <= N; i++) {
				result[type[i]]++; //해당 타입 개수 +1
				type[i] = 1; //다음 층을 위해 초기화 이때 일단 블라인드가 내려져있지 않은 1번 경우라고 가정
			}
			continue; 
		}
		for (int i = 1; i <= 1 + 5 * N; i += 5) { //창문의 맨 오른쪽 위치만 확인
			if (tmp[i] == '*') { //블라인드가 쳐져 있다면
				type[1 + (i - 1) / 5]++; //종류를 +1하여 다른 종류로 표시
			}
		}
	}

	// 결과 출력
	for (int i = 1; i < 6; i++) {
		cout << result[i] << " ";
	}
	cout << '\n';

	return 0;
}