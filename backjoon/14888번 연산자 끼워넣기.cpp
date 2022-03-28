//난이도 : 실버1
//시작 : 09:35
//끝 : 09:57
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_oper[4] = { 0 }; 
int num[11] = { 0 };
int op[11] = { 0 };
vector<int> v_result;

int calc(int N, int op[]) { //연산을 계산하는 함수
	int result = num[0];
	for (int i = 1; i < N; i++) {
		if (op[i - 1] == 0) { //0은 +
			result += num[i];
		}
		else if (op[i - 1] == 1) { //1은 -
			result -= num[i];
		}
		else if (op[i - 1] == 2) { //2는 *
			result *= num[i];
		}
		else if (op[i - 1] == 3) { //3은 /
			result /= num[i];
		}
	}
	return result;
}

bool is_available(int op) {
	if (num_oper[op] == 0) { //해당 연산자가 남아있지 않은 경우
		return false;
	}
	num_oper[op]--; //연산자를 사용했으니 남은 개수를 하나 감소
	return true;
}

void DFS(int N, int cur) { //DFS
	if (N - 1 == cur) { //연산자를 모두 채운 경우
		int result = calc(N, op); //결과 계산
		v_result.push_back(result); //벡터 저장
		//cout << result << '\n';
	}
	for (int i = 0; i < 4; i++) { //모든 연산자 대입
		op[cur] = i;
		if (is_available(i)) {
			DFS(N, cur + 1); // DFS
			num_oper[i]++; //다른 경우의 수를 찾기 위해서 사용한 연산자를 다시 늘려준다.
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
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> num_oper[i];
	}

	DFS(N, 0);

	cout << *max_element(v_result.begin(), v_result.end()) << '\n'; //벡터 내 최대값 출력
	cout << *min_element(v_result.begin(), v_result.end()) << '\n'; //벡터 내 최소값 출력


	return 0;
}