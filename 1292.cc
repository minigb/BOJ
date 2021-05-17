#include <iostream>
using namespace std;

pair<int, int> getNumAndCount(int a) {
	for (int i = 0; ; i++) {
		if (a > i) {
			a -= i;
		}
		else {
			return { i, a };
		}
	}
}

int sumOfNSquares(int a) {
	return a * (a + 1) / 2 * (2 * a + 1) / 3;
}

int sumUntilThat(pair<int, int> a) {
	int ret = 0;
	ret += sumOfNSquares(a.first - 1);
	ret += a.first * a.second;
	return ret;
}

int solution(int a, int b) {
	pair<int, int> numAndCountBeforeA = getNumAndCount(a - 1);
	pair<int, int> numAndCountOfB = getNumAndCount(b);

	return sumUntilThat(numAndCountOfB) - sumUntilThat(numAndCountBeforeA);
}

int main() {
	int a, b; cin >> a >> b;
	cout << solution(a, b);
}
