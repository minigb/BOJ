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

class Status {
public:
	int size, time, x;
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	queue<Status> que;
	que.push({ 1, 0, 0 });
	int ans = 1;
	while (!que.empty()) {
		Status cur = que.front();
		que.pop();

		if (cur.time == m || cur.x == n) {
			ans = max(ans, cur.size);
			continue;
		}

		que.push({ cur.size + arr[cur.x + 1], cur.time + 1, cur.x + 1 });
		if (cur.x + 2 <= n) {
			que.push({ cur.size / 2 + arr[cur.x + 2], cur.time + 1, cur.x + 2 });
		}
	}

	cout << ans << ENDL;
	return 0;
}
