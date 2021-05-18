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
	int n, m, v; cin >> n >> m >> v;
	vector<vector<int>> neighbors(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		neighbors[a].push_back(b);
		neighbors[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(neighbors[i].begin(), neighbors[i].end());
	}

	stack<int> stck;
	vector<bool> visited(n + 1);
	stck.push(v);
	visited[v] = true;
	cout << v << ' ';

	while (!stck.empty()) {
		int cur = stck.top();
		stck.pop();

		for (int next : neighbors[cur]) {
			if (visited[next]) {
				continue;
			}
			visited[next] = true;
			stck.push(cur);
			stck.push(next);
			cout << next << ' ';
			break;
		}
	}

	cout << kEndl;
	visited.clear();
	visited.resize(n + 1, false);
	queue<int> que;
	que.push(v);
	visited[v] = true;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		cout << cur << ' ';
		
		for (int next : neighbors[cur]) {
			if (visited[next]) {
				continue;
			}
			visited[next] = true;
			que.push(next);
		}		
	}
	cout << kEndl;
}
