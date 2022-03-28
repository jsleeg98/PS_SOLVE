//시작 : 23:10
//끝 : 24:55
//한 거리에 대해서 물을 뿌리고 모두 이동한 뒤 계산해야하는데 계속 물을 뿌려서 실패했지만 
//이는 distance_map과 tree_depth를 이용하여 해결하였다.
//tree_depth와 distance_map이 같을 때는 물을 뿌리지 않도록 하여 같은 상황에서 S를 움직였다.
#include <iostream>
#include <string>
#include <queue>

using namespace std;

vector<pair<int, int>> water;

//물 뿌리기
//맵 배열, 현재 r, 현재 c, 맵 전체 R, 맵 전체 C
void watering(char input_map[51][51], int R, int C) {
	vector<pair<int, int>> tmp_water;
	int dC[4] = { 1, 0, -1, 0 };
	int dR[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < water.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int next_r = water[i].first + dR[j];
			int next_c = water[i].second + dC[j];
			if (next_r > 0 && next_r < R + 1
				&& next_c > 0 && next_c < C + 1) {
				if (input_map[next_r][next_c] == '.') {
					input_map[next_r][next_c] = '*';
					tmp_water.push_back(make_pair(next_r, next_c)); //물 좌표 임시 저장, 이렇게 하지 않으면 한번에 물이 다 뿌려짐
				}
			}

		}
	}
	//임시 물 좌표를 본 물 좌표에 추가
	for (int i = 0; i < tmp_water.size(); i++) {
		water.push_back(tmp_water[i]);
	}
}

//맵 출력
void print_map(char input_map[51][51], int R, int C) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << input_map[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string line[51];
	char input_map[51][51];
	int visited_map[51][51] = { 0 };
	queue<pair<int, int>> queue;
	int distance_map[51][51] = { 0 };
	int dC[4] = { 1, 0, -1, 0 };
	int dR[4] = { 0, 1, 0, -1 };
	int start_R, start_C, end_R, end_C;
	bool stop = false;
	int tree_depth = -1;

	int R, C;
	cin >> R >> C; //행, 열 입력

	//라인 단위 문자열 입력
	for (int i = 1; i <= R; i++) {
		cin >> line[i];
	}

	//맵 입력
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			input_map[i][j] = line[i][j - 1];
			if (input_map[i][j] == 'S') { //시작 좌표 초기화
				start_R = i;
				start_C = j;
				input_map[i][j] = '.';
			}
			else if (input_map[i][j] == 'D') {
				end_R = i;
				end_C = j;
			}
			else if (input_map[i][j] == '*') {
				water.push_back(make_pair(i, j));
			}
		}
	}

	visited_map[start_R][start_C] = 1; //시작 위치 방문 처리
	queue.push(make_pair(start_R, start_C)); //큐에 좌표 삽입
	while (queue.size() != 0 && stop == false) {
		int r = queue.front().first;
		int c = queue.front().second;
		queue.pop(); //큐에서 pop
		input_map[r][c] = '.'; //현재 위치 . 처리

		if (tree_depth < distance_map[r][c]) {
			watering(input_map, R, C); //물 뿌리기
			tree_depth++;
		}
		
		
	
		//print_map(input_map, R, C); //맵 출력
		//cout << "-----------------\n"; //구분선
		

		
		//움직일 수 있는 좌표 확인
		for (int i = 0; i < 4; i++) {
			int next_r = r + dR[i];
			int next_c = c + dC[i];
			if (next_r > 0 && next_r < R + 1
				&& next_c > 0 && next_c < C + 1) { //맵을 넘어가지 않는 경우
				if (input_map[next_r][next_c] == '.' || input_map[next_r][next_c] == 'D') { //.이나 S로 움직일 수 있는 경우
					if (visited_map[next_r][next_c] == 0) { //방문하지 않은 경우
						distance_map[next_r][next_c] = distance_map[r][c] + 1; //거리 1 추가
						visited_map[next_r][next_c] = 1; //방문 처리
						queue.push(make_pair(next_r, next_c)); //큐에 push

						//input_map[next_r][next_c] = 'S'; //D가 있을 수 있는 좌표 표시
						if (input_map[next_r][next_c] == 'D') { //S에 도달한 경우
							stop = true; //멈춤
							break;
						}
							
					}
				}
			}
		}
		//print_map(input_map, R, C); //맵 출력
		//cout << endl;
		
	}

	
	if (stop == true) { //S에 도달한 경우
		cout << distance_map[end_R][end_C] << '\n';
	}
	else { //S에 도달하지 못한 경우
		cout << "KAKTUS" << '\n';
	}
	


	return 0;
}