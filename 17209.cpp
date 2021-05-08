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
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int ans = 0;
	vector<bool> chk(n, false);
	for (int i = 0; i < n; i++) {
		if (chk[i] == false) {
			chk[i] = true;
			int countAll = 0;
			int countTrue = 0;
			queue<pair<int, bool>> que;
			que.push({ i, true });
			while (!que.empty()) {
				int cur = que.front().first;
				bool flag = que.front().second;
				que.pop();

				countAll++;
				if (flag) countTrue++;
				
				for (int next : adj[cur]) {
					if (chk[next]) continue;
					chk[next] = true;
					que.push({ next, !flag });
				}
			}
			ans += max(countTrue, countAll - countTrue);
		}
	}

	cout << ans << ENDL;
	return 0;
}
