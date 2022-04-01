//난이도 : 실버2
//시작 : 09:25
//끝 : 
#include <iostream>
#include <vector>

using namespace std;

int arr[21][21] = { 0 }; //능력치 저장 배열

int team_start[10] = { 0 }; //start 팀 사람 번호
int team_link[10] = { 0 }; //link 팀 사람 번호
int result = 1000; //결과 


bool is_available(int cur, int num) {
	for (int i = 0; i < cur; i++) { 
		if (team_start[i] >= num) { //이전에 선정한 사람이 현재 사람과 같거나 작으면 탈락한다. 
			//그 이유는 같으면 같은 사람을 뽑은 것이니 안되고 작으면 이전에 이미 찾은 경우의 수이기 때문 
			return false; //탈락
		}
	}
	return true;
}

void DFS(int N, int cur) {
	if (N / 2 == cur) { //start 팀 사람을 다 뽑은 경우
		int member[21] = { 0 };
		for (int i = 0; i < N / 2; i++) { //start 팀에 뽑힌 사람을 1로 처리
			member[team_start[i]] = 1;
		}
		int j = 0;
		for (int i = 1; i <= N; i++) { //link 팀에 뽑힌 사람은 0으로 처리되어 있으며 이를 이용하여 team_link 배열에 사람 번호 입력
			if (member[i] == 0) {
				team_link[j] = i;
				j++;
			}
		}
		//for (int i = 0; i < cur; i++) {
		//	cout << team_start[i] << " ";
		//}
		//cout << '\n';
		//for (int i = 0; i < cur; i++) {
		//	cout << team_link[i] << " ";
		//}
		//cout << '\n';
		int link_score = 0; //link 팀 능력치
		int start_score = 0; //start 팀 능력치
		for (int i = 0; i < N / 2; i++) { //2차원 배열을 순회 할 때 link팀과 start팀의 능력치를 하나하나 계산
			for (int j = 0; j < N / 2; j++) {
				link_score += arr[team_link[i]][team_link[j]];
				start_score += arr[team_start[i]][team_start[j]];
			}
		}
		//cout << link_score << " " << start_score << '\n';
		if (result > abs(link_score - start_score)) { //능력치의 차이를 계산하고 그 차이가 가장 작은 것은 result에 저장
			result = abs(link_score - start_score);
		}
		return;
	}
	for (int i = cur + 1; i <= N; i++) { //1 2를 선택하는 것과 2 1을 선택하는 것은 같으므로 생략하기 위해 cur + 1부터 선택
		team_start[cur] = i; //사람 번호 넣기
		if (is_available(cur, i)) {
			DFS(N, cur + 1);
			team_start[cur] = 0; //다른 경우의 수를 찾기 위해 0으로 초기화
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	
	DFS(N, 0);

	cout << result << '\n';
	return 0;
}