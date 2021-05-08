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
#define ENDL '\n'
#define PI acos(-1)

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, burger, fries; cin >> n >> burger >> fries;
	vector<pair<int, int>> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(burger + 1, vector<int>(fries + 1)));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= burger; j++) {
			for (int k = 0; k <= fries; k++) {
				dp[i][j][k] = dp[i - 1][j][k];
				if(j >= arr[i].first && k >= arr[i].second)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - arr[i].first][k - arr[i].second] + 1);
			}
		}
	}

	cout << dp[n][burger][fries] << ENDL;

	return 0;
}
