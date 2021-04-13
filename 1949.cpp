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

int N;
vector<int> people;
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<bool> chk;
void sol(int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i;

	cin >> N;
	people.resize(N + 5);
	for (i = 1; i <= N; i++) {
		cin >> people[i];
	}
	adj.resize(N + 5);
	for (i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dp.resize(2, vector<int>(N + 5, -1));
	chk.resize(N + 5, false);
	chk[1] = true;
	sol(1);
  
	cout << max(dp[0][1], dp[1][1]) << ENDL;

	return 0;
}

void sol(int cur)
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
		sol(next);
		dp[0][cur] += max(dp[0][next], dp[1][next]);
		dp[1][cur] += dp[0][next];
	}
	dp[1][cur] += people[cur];

	return;
}
