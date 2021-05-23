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
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << kEndl;
	}
	else {
		for (int i = 0; i + 1 < n; i += 2) {
			cout << "1 2 ";
		}
		if (n % 2 == 1) {
			cout << 3;
		}
	}	
}
