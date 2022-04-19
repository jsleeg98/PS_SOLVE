//난이도 : 실버1
//시작 : 20:36
//끝 : 22:38
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int chair[22][22]; //상하좌우 padding 1
int N; 

//r, c 위치에서 빈칸의 수와 좋아하는 번호 수 저장 구조체
struct info {
	int vacant = 0;
	int like = 0;
	int r;
	int c;
};


//r, c 위치에서 인접한 곳에 빈칸이 있는 개수 반환 함수
int vacant_chair_num(int r, int c) {
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int vacant = 0;
	for (int i = 0; i < 4; i++) {
		int rr = r + dir[i][0];
		int cc = c + dir[i][1];
		if (rr == 0 || rr == N + 1 || cc == 0 || cc == N + 1) {
			continue; //테두리는 패스
		}
		if (chair[rr][cc] == 0) {
			vacant++; //빈칸 +1
		}
	}
	return vacant;
}

//r, c 위치에서 인접한 곳에 좋아하는 번호의 개수 반환 함수
int like_chair_num(int r, int c, vector<int> like_num) {
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int like = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			int rr = r + dir[i][0];
			int cc = c + dir[i][1];
			if (chair[rr][cc] == like_num[j]) {
				like++; //빈칸 +1
			}
		}
	}
	
	return like;
}

//비교 우선순위
//1. 주변에 좋아하는 사람 수 많은 순
//2. 주변에 빈칸이 많은 순
//3. 행 번호가 작은 순
//4. 열 번호가 작은 순
bool compare(info a, info b) {
	if (a.like > b.like) {
		return true;
	}
	else if (a.like == b.like) {
		if (a.vacant > b.vacant) {
			return true;
		}
		else if (a.vacant == b.vacant) {
			if (a.r < b.r) {
				return true;
			}
			else if (a.r == b.r) {
				if (a.c < b.c) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> v_like_info[401];
	int result = 0;

	cin >> N;
	for (int i = 0; i < N*N; i++) {
		int num;
		cin >> num;
		
		vector<int> like_num; //좋아하는 사람 벡터 배열
		for (int i = 0; i < 4; i++) {
			int tmp;
			cin >> tmp;
			like_num.push_back(tmp);
		}

		v_like_info[num].push_back(like_num); //num 인덱스에 좋아하는 사람 벡터 push

		vector<info> v; //현재 num 기준 비교할 info 벡터 생성
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (chair[r][c] == 0) { //현재 위치가 빈칸인 경우에만 수행
					int like = like_chair_num(r, c, like_num); //주변에 좋아하는 사람 수 저장
					int vacant = vacant_chair_num(r, c); //주변에 빈칸 수 저장
					info tmp;
					tmp.r = r; //현재 행 
					tmp.c = c; //현재 열
					tmp.like = like;
					tmp.vacant = vacant;
					v.push_back(tmp); //벡터에 push
				}
				
			}
		}
		sort(v.begin(), v.end(), compare); //비교를 통해 우선순위에 따라 정렬
		chair[v[0].r][v[0].c] = num; //맨앞에 있는 위치에 현재 num 넣기


		//중간 결과 출력
		/*for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				cout << chair[r][c] << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
	}

	//만족도 조사
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 1) {
				result += 1;
			}
			else if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 2) {
				result += 10;
			}
			else if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 3) {
				result += 100;
			}
			else if (like_chair_num(r, c, v_like_info[chair[r][c]][0]) == 4) {
				result += 1000;
			}
		}
	}

	//만족도 출력
	cout << result << '\n';
	

	return 0;
}