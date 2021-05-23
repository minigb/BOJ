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
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	vector<int> mistake(n + 1, 0);
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i + 1]) {
			mistake[i] = 1;
		}
		mistake[i] += mistake[i - 1];
	}

	int q; cin >> q;
	while (q--) {
		int x, y; cin >> x >> y;
		cout << mistake[y - 1] - mistake[x - 1] << kEndl;
	}
}
