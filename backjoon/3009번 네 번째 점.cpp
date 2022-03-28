//시작 : 17:36
//끝 : 17:45

#include <iostream>

using namespace std;

int main() {
	int x[3];
	int y[3];
	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
	}
	//맨 앞에 있다고 가정
	int idx_x = 0; 
	int idx_y = 0;

	//같은게 있다면 탈락
	for (int i = 1; i < 3; i++) {
		if (x[0] == x[i]) {
			idx_x = 3 - i;
		}
		if (y[0] == y[i]) {
			idx_y = 3 - i;
		}
	}
	cout << x[idx_x] << " " << y[idx_y] << '\n';
	return 0;
}