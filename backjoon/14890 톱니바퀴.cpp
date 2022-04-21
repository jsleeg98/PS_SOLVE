//난이도 : 골드5
//시작 : 10:36
//끝 : 11:23
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int wheel[5][8]; //톱니 바퀴의 상태 저장 // 1번부터 4번 인덱스 사용

//톱니 회전 시키는 함수
void rotate(int wheel_num, int dir) {
	if (dir == 1) {//시계 방향 회전인 경우
		int tmp = wheel[wheel_num][7];
		for (int i = 7; i > 0; i--) {
			wheel[wheel_num][i] = wheel[wheel_num][i - 1];
		}
		wheel[wheel_num][0] = tmp;
	}
	else if (dir == -1) { //반시계 방향 회전인 경우
		int tmp = wheel[wheel_num][0];
		for (int i = 0; i < 7; i++) {
			wheel[wheel_num][i] = wheel[wheel_num][i + 1];
		}
		wheel[wheel_num][7] = tmp;
	}
}

queue<pair<int, int>> check(int wheel_num, int dir) {
	queue<pair<int, int>> q;
	q.push(make_pair(wheel_num, dir)); //현재 톱니 돌리기 큐에 push
	
	if (wheel_num == 1) { //1번을 돌리는 경우
		if (wheel[1][2] != wheel[2][6]) {//2번 맞물림
			dir *= -1;
			q.push(make_pair(2, dir)); //2번 추가
			if (wheel[2][2] != wheel[3][6]) { //3번 맞물림
				dir *= -1;
				q.push(make_pair(3, dir)); //3번 추가
				if (wheel[3][2] != wheel[4][6]) { //4번 맞물림
					dir *= -1;
					q.push(make_pair(4, dir)); //4번 추가
				}
			}
		}
	}
	else if (wheel_num == 2) {
		dir *= -1;
		if (wheel[2][6] != wheel[1][2]) {//1번 맞물림
			q.push(make_pair(1, dir));//1번 추가
		}
		if (wheel[2][2] != wheel[3][6]) { //3번 맞물림
			q.push(make_pair(3, dir));//3번 추가
			if (wheel[3][2] != wheel[4][6]) {//4번 맞물림
				dir *= -1;
				q.push(make_pair(4, dir));//4번 추가
			}
		}
	}
	else if (wheel_num == 3) {
		dir *= -1;
		if (wheel[3][2] != wheel[4][6]) {//4번 맞물림
			q.push(make_pair(4, dir)); //4번 추가
		}
		if (wheel[3][6] != wheel[2][2]) {//2번 맞물림
			q.push(make_pair(2, dir));//2번 추가
			if (wheel[2][6] != wheel[1][2]) {//1번 맞물림
				dir *= -1;
				q.push(make_pair(1, dir)); //1번 추가
			}
		}
	}
	else if (wheel_num == 4) {
		if (wheel[4][6] != wheel[3][2]) { //3번 맞물림
			dir *= -1;
			q.push(make_pair(3, dir)); //3번 추가
			if (wheel[3][6] != wheel[2][2]) { //2번 맞물림
				dir *= -1;
				q.push(make_pair(2, dir));//2번 추가
				if (wheel[2][6] != wheel[1][2]) {//1번 맞물림
					dir *= -1;
					q.push(make_pair(1, dir)); //1번 추가
				}
			}
		}
	}
	return q;
}

//큐에 담겨있는 회전 정보에 따라 톱니 바퀴를 회전시키는 함수
void wheel_rotate(queue<pair<int, int>> q) {
	while (!q.empty()) {
		int wheel_num = q.front().first;
		int dir = q.front().second;
		q.pop();
		rotate(wheel_num, dir); //톱니바퀴 회전
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//string으로 한줄을 입력 받고 이를 숫자로 바꾸기 위해 48을 빼서 바꾼다.
	//그리고 이를 int 배열에 넣는다.
	for (int i = 1; i <= 4; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = (int)tmp[j] - 48;
		}
	}

	//for (int i = 1; i <= 4; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		cout << wheel[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int wheel_num, dir;
		cin >> wheel_num >> dir;
		queue<pair<int, int>> q;
		q = check(wheel_num, dir); //톱니 바퀴 맞물림 확인하기
		wheel_rotate(q); //톱니바퀴 돌리기
	}

	//for (int i = 1; i <= 4; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		cout << wheel[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	//결과 점수
	int result = 0;
	for (int i = 1; i <= 4; i++) {
		if (wheel[i][0] == 1) { //S극 이라면 
			result += pow(2, i-1); //2의 제곱하여 점수 들어감
		}
	}

	cout << result << '\n'; //점수 출력

	return 0;
}