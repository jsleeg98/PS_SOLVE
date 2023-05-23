//난이도 : 
//시작 : 
//끝 :
#include <iostream>
#include <vector>
#include <array>

#define inf 987654321

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 방향
	vector<pair<int, int>> dir;
	dir.push_back({ -1, 1 });
	dir.push_back({ -1, 0 });
	dir.push_back({ -1, -1 });
	
	vector<vector<int>> map;
	int N, M;
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		vector<int> tmp;
		for (int c = 0; c < M; c++) {
			int t;
			cin >> t;
			tmp.push_back(t);
		}
		map.push_back(tmp);
	}
	
	// DP 초기화
	vector<vector<vector<int>>> DP;
	vector<vector<int>> DP_tmp;
	for (int c = 0; c < M; c++) {
		vector<int> tmp;
		for (int i = 0; i < 3; i++) {
			tmp.push_back(map[0][c]);
		}
		DP_tmp.push_back(tmp);
	}
	DP.push_back(DP_tmp);



	for (int r = 1; r < N; r++) {
		vector<vector<int>> tmp_dp_dp;
		for (int c = 0; c < M; c++) {
			vector<int> tmp_dp;
			for (int d = 0; d < 3; d++) {
				vector<int> tmp;
				int nr = r + dir[d].first;
				int nc = c + dir[d].second;
				if (nc < 0 || nc >= M) {  // 맵의 열 넘어가는 경우
					tmp_dp.push_back(inf);
				}
				else {
					tmp = DP[nr][nc];
					int min = inf;
					for (int i = 0; i < 3; i++) {
						if (i == d) continue;  // 2번 연속 같은 방향 피하기
						if (min > tmp[i]) {
							min = tmp[i];
						}
					}
					tmp_dp.push_back(min + map[r][c]);
				}
			}
			tmp_dp_dp.push_back(tmp_dp);
		}
		DP.push_back(tmp_dp_dp);
		//for (int r = 0; r < DP.size(); r++) {
		//	for (int c = 0; c < DP[0].size(); c++) {
		//		cout << DP[r][c][0] << "|";
		//		cout << DP[r][c][1] << "|";
		//		cout << DP[r][c][2] << "  ";
		//	}
		//	cout << '\n';
		//}
		//cout << "-------------\n";
	}

	// DP 마지막 행의 가장 작은 수 출력
	int min = inf;
	for (int c = 0; c < M; c++) {
		for (int d = 0; d < 3; d++) {
			if (min > DP[N - 1][c][d]) {
				min = DP[N - 1][c][d];
			}
		}
	}

	cout << min << '\n';


	return 0;
}