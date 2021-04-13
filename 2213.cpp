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
#define ENDL '\n'
#define PI acos(-1)

vector<int> w;
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<bool> chk;
vector<int> ans;

void solve(int);
void getAns(int cur, bool flag);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int i;
	
	cin >> N;
	w.resize(N + 5);
	for (i = 1; i <= N; i++) {
		cin >> w[i];
	}
	adj.resize(N + 5);
	for (i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dp.resize(2, vector<int> (N + 5, -1));
	chk.resize(N + 5, false);
	chk[1] = true;
	solve(1);

	cout << max(dp[0][1], dp[1][1]) << ENDL;

	chk.clear(); chk.resize(N + 5, false);
	chk[1] = true;
	dp[0][1] > dp[1][1] ? getAns(1, false) : getAns(1, true);

	sort(ans.begin(), ans.end());
	for (int n : ans) {
		cout << n << ' ';
	}
	cout << ENDL;

	return 0;
}

void solve(int cur)
{
	if (dp[0][cur] != -1) {
		return;
	}

	dp[0][cur] = dp[1][cur] = 0;
	for (int next : adj[cur]) {
		if (chk[next]) {
			continue;
		}

		chk[next] = true;
		solve(next);
		dp[0][cur] += max(dp[0][next], dp[1][next]);
		dp[1][cur] += dp[0][next];
	}
	dp[1][cur] += w[cur];
}

void getAns(int cur, bool flag)
{
	if (flag) {
		ans.push_back(cur);
		for (int next : adj[cur]) {
			if (chk[next]) {
				continue;
			}
			chk[next] = true;
			getAns(next, false);
		}
	}
	else {
		for (int next : adj[cur]) {
			if (chk[next]) {
				continue;
			}
			chk[next] = true;
			dp[0][next] > dp[1][next] ? getAns(next, false) : getAns(next, true);
		}
	}
}
