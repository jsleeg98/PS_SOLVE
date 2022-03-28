//시작 15:50
//끝 17:16

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	vector<int> ans;
	int x1, y1, r1, x2, y2, r2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//l은 중심 사이의 거리로 double로 선언해야 맞다.
		//int로 선언하는 경우 소수자리가 버려져 제대로된 비교가 불가능하기 때문
		double l = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (r1 == r2 && l == 0) { //교점이 무한히 나오는 경우
			ans.push_back(-1);
		}
		else if (r1 + r2 == l || abs(r1 - r2) == l) { //외접, 내접하는 경우
			ans.push_back(1);
		}
		else if (abs(r1 - r2) < l && l < r1 + r2) { //교점이 2개인 경우
			ans.push_back(2);
		}
		else { //나머지
			ans.push_back(0);
		}

		
		
		
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}


	return 0;
}