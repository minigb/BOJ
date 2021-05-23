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
	int n = 12;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 3) {
			vector<bool> degree(4, false);
			for (int next : adj[i]) {
				degree[adj[next].size()] = true;
			}
			if (degree[1] && degree[2] && degree[3]) {
				ans = i;
				break;
			}
		}
	}
	
	cout << ans << kEndl;
}
