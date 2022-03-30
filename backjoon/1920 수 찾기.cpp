//난이도 : 실버4
//시작 : 11:08
//끝 : 11:22
#include <iostream>
#include <algorithm>

using namespace std;

int A[100000]; //배열을 저장

//Binary Search 알고리즘
//BS(0, 4, 5)는 인덱스 0, 1, 2, 3에서 5를 찾는다는 의미
int BS(int start, int end, int search) { //시작, 끝, 검색할 숫자
	if (end - start == 1 && search == A[start]) { //배열의 크기가 1인 경우 남아 있는 숫자가 검색하는 수인지 확인하여 맞으면
		return 1; //1 반환
	}
	if (end - start == 1 && search != A[start]) { //검색하는 수가 아니면
		return 0; //0 반환
	}
	if (end - start == 0) { //배열의 크기가 0인 경우, 방어 코드
		return 0; //0 반환
	}

	int medium = (start + end) / 2; //중간 인덱스 값
	if (search == A[medium]) { //중간 인덱스의 값이 검색하는 수이면
		return 1; //1 반환
	}
	else { //중간 인덱스의 값이 검색하는 수가 아닌 경우
		if (search > A[medium]) { //검색하는 수가 중간 값보다 큰 경우
			return BS(medium, end, search); //오른쪽에서 다시 검색 재귀적, 이분할
		}
		else if (search < A[medium]) { //검색하는 수가 중간 값보다 작은 경우
			return BS(start, medium, search); //왼쪽에서 다시 검색 재귀적, 이분할
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N); //오름차순 정렬을 반드시 해주어야 이분탐색이 가능하다.
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
		cout << BS(0, N, tmp) << '\n';
	}

	return 0;
}