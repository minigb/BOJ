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
	vector<pair<int, int>> arr(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int k; cin >> k;

	vector<vector<int>> dp(n + 1, vector<int>(2, INT_MAX));
	dp[1][0] = dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i - 1].first);
		}
		if (i - 2 >= 1) {
			for (int j = 0; j < 2; j++) {
				dp[i][j] = min(dp[i][j], dp[i - 2][j] + arr[i - 2].second);
			}			
		}
		if (i - 3 >= 1) {
			dp[i][1] = min(dp[i][1], dp[i - 3][0] + k);
		}
	}

	cout << min(dp[n][0], dp[n][1]) << kEndl;
}
