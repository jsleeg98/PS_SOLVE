//시작 : 21:31
//끝 : 22:50
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N;
struct pos {
	int r;
	int c;
};

vector<pos> person; //사람의 위치 저장 벡터
vector<pair<pos, int>> stair; //계단의 위치와 길이 저장 벡터
int result = 987654321; //최종 결과

void print(vector<int> v) {
	for (int i = 0; i < person.size(); i++) {
		cout << v[i] << " ";
	}
	cout << '\n';
}

//입력
void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				person.push_back({ r, c });
			}
			else if (tmp >= 2) {
				stair.push_back({ {r, c}, tmp });
			}
		}
	}
}

void init() {
	person.clear(); //다음을 위해 사람 위치 벡터 초기화
	stair.clear(); //다음을 위해 계단 위치 벡터 초기화
	result = 987654321; //다음을 위해 최종 결과 초기화
}

//현재 들어온 경우의 수의 걸리는 시간 계산 함수
void solve(vector<int> v) {
	//print(v);
	//a와 b에 각 계단에 갈 사람들과 계단의 거리 추가 
	//a는 첫번째 계단 이용자
	//b는 두번째 계단 이용자
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			pos tmp = person[i];
			int distance = abs(stair[0].first.r - tmp.r) + abs(stair[0].first.c - tmp.c);
			a.push_back(distance);
		}
		else {
			pos tmp = person[i];
			int distance = abs(stair[1].first.r - tmp.r) + abs(stair[1].first.c - tmp.c);
			b.push_back(distance);
		}
	}

	
	

	queue<int> q_a;
	queue<int> q_b;
	
	int time_a; //첫번째 계단 이용자의 걸리는 시간
	int time_b; //두번째 계단 이용자의 걸리는 시간

	
	if (a.size() == 0) {//첫번째 계단을 이용하는 사람이 없는 경우
		time_a = 0; //걸리는 시간 0
	}
	else if (a.size() <= 3) { //첫번째 계단을 이용하는 사람이 3명 이하인 경우 
		sort(a.begin(), a.end()); //도착하는 시간 오름차순 정렬 
		time_a = a[a.size() - 1] + stair[0].second; //마지막 사람이 계단을 다 내려간 시간이 결과가 됨
	}
	else { //첫번째 계단을 이용하는 사람이 3명 초과인 경우
		sort(a.begin(), a.end()); //도착하는 시간 오름차순 정렬
		//queue에 3명 넣기
		q_a.push(a[0]);
		q_a.push(a[1]);
		q_a.push(a[2]);
		int idx = 3; //첫번째계단 이용자를 선택하기 위한 인덱스
		while (!q_a.empty()) { //queue가 빌 때가지 반복
			int cur_time = q_a.front() + stair[0].second; //맨 앞 사람의 나가는 시간
			q_a.pop();
			if (idx < a.size()) { //이용자가 남아 있는 경우
				if (cur_time > a[idx]) { //맨 앞 사람이 나가는 시간보다 다음 queue에 넣을 사람의 도착시간이 빠른 경우 
					a[idx] += cur_time - a[idx]; //queue에 넣을 사람의 도착 시간을 맨 앞사람이 나가는 시간과의 차이만큼 딜레이 시킨다.
					q_a.push(a[idx]); //queue에 넣는다.
				}
				else { //맨 앞 사람이 나가는 시간보다 다음 queue에 넣을 사람의 도착시간이 느린 경우 
					q_a.push(a[idx]); //도착 시간 수정없이 queeu에 넣는다.
				}
				idx++; //다음 사람을 선택하기 위해 ++
			}
			time_a = cur_time; //마지막까지 수행하면 결국 time_a에는 첫번째 계단을 이용하는 사람들이 걸리는 시간이 저장된다.
		}
	}
	
	//두번째 계단도 첫번째 계단과 동일하게 적용된다.
	if (b.size() == 0) {
		time_b = 0;
	}
	else if (b.size() <= 3) {
		sort(b.begin(), b.end());
		time_b = b[b.size() - 1] + stair[1].second;
	}
	else {
		sort(b.begin(), b.end());
		q_b.push(b[0]);
		q_b.push(b[1]);
		q_b.push(b[2]);
		int idx = 3;
		while (!q_b.empty()) {
			int cur_time = q_b.front() + stair[1].second;
			q_b.pop();
			if (idx < b.size()) {
				if (cur_time > b[idx]) {
					b[idx] += cur_time - b[idx];
					q_b.push(b[idx]);
				}
				else {
					q_b.push(b[idx]);
				}
				idx++;
			}
			time_b = cur_time;
		}
	}
	//cout << time_a << " " << time_b << '\n';
	int result_time = max(time_a, time_b); //첫번째 계단과 두번째 계단에 걸리는 시간 중 오래 걸리는 것이 최종 걸리는 시간이다.

	//문제의 해답은 모든 경우의 최종 걸리는 시간 중 최소 값이다.
	result = min(result_time, result);
	


}

//모든 경우의 수 파악을 위한 DFS
void DFS(vector<int> v, int cur, int p) {
	if (cur == p) { //모든 사람의 경우를 선택한 경우
		solve(v); //걸리는 시간 계산
		return; //종료
	}
	//0은 첫번째 계단, 1은 두번째 계단
	for (int i = 0; i <= 1; i++) {
		v.push_back(i); 
		DFS(v, cur + 1, p); //다음 사람의 경우의 수 찾기 위함
		v.pop_back(); //다른 경우의 수 찾기 위함
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		input();
		vector<int> v;
		DFS(v, 0, person.size());
		cout << "#" << test_case << " " << result + 1 << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}