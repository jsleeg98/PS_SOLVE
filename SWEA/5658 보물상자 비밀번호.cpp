//시작 : 16:53
//끝 : 17:55
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int N; //숫자의 개수
int K; //순위
int cut;
deque<char> number;
vector<long long int> result;

void init() {
	number.clear();
	result.clear();
}

//문자를 십진수로 바꾸는 함수
int change_10(char a) {
	int tmp = (int)a;
	if (tmp >= 65) {
		tmp -= 65; //알파벳 A는 65 이므로 
		tmp += 10; //A부터 10이므로 +10
	}
	else { //문자인 수자 이므로 -48
		tmp -= 48;
	}
	return tmp;
}

void get_number() {
	for (int i = 0; i < number.size(); i += cut) {
		long long int tmp_result = 0;
		for (int j = 0; j < cut; j++) {
			char tmp = number[i + j];
			int num = change_10(tmp);
			//cout << num << '\n';
			tmp_result += num * pow(16, cut - 1 - j);
		}
		result.push_back(tmp_result);
	}

	//cout << result.size() << '\n';
}

void rotate() {
	char tmp;
	tmp = number.back();
	number.pop_back();
	number.push_front(tmp);
}

long long int final_result() {
	long long int final_result_num;
	int cnt = 1;
	long long int before = result[0];
	if (K == 1) { //1등 추출 처리
		return result[0];
	}
	for (int i = 1; i < result.size(); i++) {
		//cout << result[i] << '\n';
		if (before != result[i]) { //중복 처리
			before = result[i];
			cnt++;
		}
		if (cnt == K) { // 해당 등수 인 경우 멈춤
			final_result_num = result[i];
			break;
		}
	}
	return final_result_num;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> N >> K;
		cut = N / 4;
		string tmp;
		cin >> tmp;
		for (int i = 0; i < tmp.length(); i++) {
			number.push_back(tmp[i]);
		}
		get_number();
		for (int i = 0; i < cut - 1; i++) {
			rotate();
			get_number();
		}

		sort(result.begin(), result.end());
		reverse(result.begin(), result.end());
		
		int ans = final_result();
		cout << "#" << test_case << " " << ans << '\n';
	
		




	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}