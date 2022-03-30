//난이도 : 실버4
//시작 : 23:24
//끝 : 01:21
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int arr_1[500000] = { 0 };
vector<pair<int, int>> arr_2;

//이진 탐색으로 vector를 탐색하여 first에는 숫자가 second에는 숫자의 개수가 들어있다.
int BS(int start, int end, int num) {
	if (end - start == 1 && arr_2[start].first == num) { //찾은 경우
		return arr_2[start].second; //해당 숫자의 개수 출력
	}
	if (end - start == 1 && arr_2[start].first != num) { //못 찾은 경우
		return 0; //0을 출력
	}
	if (end - start == 0) { //못찾은 경우
		return 0; //0을 출력
	}
	int middle = (start + end) / 2; //중간 인덱스 구하기
	if (arr_2[middle].first == num) { //찾은 경우
		return arr_2[middle].second; //해당 번호의 개수 출력
	}
	else { //못찾은 경우
		if (num < arr_2[middle].first) { //찾으려는 수가 중간 값보다 작은 경우
			return BS(start, middle, num); //왼쪽에서 BS
		}
		else if (num > arr_2[middle].first) { //찾으려는 수가 중간 값보다 큰 경우
			return BS(middle + 1, end, num); //오른쪽에서 BS
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) { //입력
		cin >> arr_1[i];
	}
	sort(arr_1, arr_1 + N); //오름차순 정렬
	//정렬된 배열에서 같은 숫자의 개수를 세서 vector 배열에 저장
	for (int i = 0; i < N; i++) {
		int num = arr_1[i];
		int count = 1;
		int j = 1;
		while (1) {
			if (i + j < N) { //배열의 크기를 넘지 않은 경우
				if (arr_1[i + j] == num) { //뒤의 숫자가 같으면
					count++; //숫자의 개수 +1
					j++; //다음 인덱스
				} 
				else { //뒤의 숫자가 다른 경우
					arr_2.push_back(make_pair(num, count)); //현재까지의 숫자의 개수와 숫자를 vector에 삽입
					break; //멈춤
				}
			}
			else { //배열의 크기를 넘은 경우
				arr_2.push_back(make_pair(num, count)); //현재까지의 숫자의 개수와 숫자를 vector에 삽입
				break;
			}
		}
		i = i + j - 1; //다음 숫자를 보기 위한 과정
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << BS(0, arr_2.size(), tmp) << " "; //벡터에서 이진 탐색 수행
	}
	cout << '\n';

	return 0;
}