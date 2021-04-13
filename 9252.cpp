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
#define PI 3.141592653589793238462643383279502
#define ENDL '\n'

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s1, s2;
	int len1, len2;
	int i, j;

	cin >> s1 >> s2;
	len1 = s1.length(); len2 = s2.length();
	s1 = " " + s1; s2 = " " + s2;

	vector<vector<int>> dp(len1 + 5, vector<int>(len2 + 5));
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << *max_element(dp[len1].begin() + 1, dp[len1].begin() + len2 + 1) << ENDL;

	i = len1; j = len2;
	string ans = "";
	while (i && j) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if(dp[i][j] == dp[i][j-1]) {
			j--;
		}
		else {
			ans += s1[i];
			i--; j--;
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans << ENDL;

	return 0;
}
