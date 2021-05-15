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
	int n, s, p; cin >> n >> s >> p;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = n - 1;
	bool flag = false;
	vector<bool> chk(n + 1, false);
	queue<pair<int, int>> que;
	que.push({ p, 0 });
	chk[p] = true;

	while (!que.empty()) {
		int cur = que.front().first;
		int cnt = que.front().second;
		que.pop();

		if (cur <= s) {
			ans -= cnt;
			if (flag == false) {
				flag = true;
				continue;
			}
			else {
				break;
			}
		}

		for (int next : adj[cur]) {
			if (!chk[next]) {
				chk[next] = true;
				que.push({ next, cnt + 1 });
			}
		}
	}

	cout << ans << ENDL;

	return 0;
}
