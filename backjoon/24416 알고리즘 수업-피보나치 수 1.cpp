//난이도 : 
//시작 : 
//끝 :
#include <iostream>


using namespace std;

int f[41];

int A = 0;
int B = 0;

int fib(int n) {
	if (n == 1 or n == 2) {
		A++;
		return 1;
	}
	else {
		return (fib(n - 1) + fib(n - 2));
	}
}

int fibonacci(int n) {
	//B++;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		B++;
	}

	return f[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	f[1] = 1;
	f[2] = 1;

	int N;
	cin >> N;
	fib(N);
	fibonacci(N);
	cout << A << " " << B << '\n';

	return 0;
}