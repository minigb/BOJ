#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const char kEndl = '\n';
const double kPi = acos(-1);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int odd = 0, even = 0;
	for (int i = 0; i < 3; i++) {
		int input; cin >> input;
		if (input % 2 == 1) {
			if (odd == 0) {
				odd = 1;
			}
			odd *= input;
		}
		else {
			if (even == 0) {
				even = 1;
			}
			even *= input;
		}
	}

	if (odd > 0) {
		cout << odd << kEndl;
	}
	else {
		cout << even << kEndl;
	}
}
