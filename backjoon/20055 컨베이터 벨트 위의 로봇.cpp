//난이도 : 골드5
//시작 : 
//끝 :
#include <iostream>
#include <deque>

using namespace std;

int N, K;
deque<pair<int, int>> belt;
int broke = 0;

void print() {
	for (int i = 0; i < belt.size(); i++) {
		cout << belt[i].first << " ";
	}
	cout << '\n';
}

void rotate() {
	pair<int, int> tmp;
	tmp = belt.back(); //맨 뒤에서 빼기
	belt.pop_back(); 
	belt.push_front(tmp); //맨 앞으로 넣기

}

void remove_robot() {
	//내릴 위치에 로봇 있다며 바로 내림
	if (belt[N - 1].second == 1) {
		belt[N - 1].second = 0;
	}
}

void move_robot() {
	//먼저 올린 로봇부터 시작하여 다음 칸이 비어있고 내구도가 0보다 크면
	//로봇 옮기기
	for (int i = N - 1; i >= 0; i--) {
		if (belt[i].second == 1 && belt[i + 1].second == 0 && belt[i + 1].first > 0) {
			belt[i].second = 0; 
			belt[i + 1].second = 1;
			//cout << belt[i + 1].second << '\n';
			belt[i + 1].first -= 1;
			//cout << belt[i + 1].second << '\n';
			if (belt[i + 1].first == 0) {
				broke++;
			}
		}
	}
}

void load_robot() {
	// 맨 앞에 내구도가 0보다 크다면
	//로봇 올림
	if (belt[0].first > 0) {
		belt[0].second = 1;
		belt[0].first -= 1;
		if (belt[0].first == 0) {
			broke++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N * 2; i++) {
		int tmp;
		cin >> tmp;
		belt.push_back(make_pair(tmp, 0));
	}

	int result = 0;
	while (1) {
		result++;
		//print();
		rotate(); //컨베이어 돌리기
		//print();
		remove_robot(); //로봇 내리기
		move_robot(); //로봇 움직이기
		remove_robot(); //로봇 내리기
		load_robot();  //로봇 올리기
		//print();
		if (broke >= K) { //내구도 검사
			break;
		}
	}

	//결과 출력
	cout << result << '\n';

	return 0;
}