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

bool sortby(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	ll ans = 0;
	int i, j;

	cin >> N >> M;
	vector<pair<ll, ll>> money(N + 5);
	map<ll, ll> mask;
	for (i = 0; i < N; i++) {
		cin >> money[i].first >> money[i].second;
	}
	sort(money.begin(), money.begin() + N, sortby);

	for (i = 0; i < M; i++) {
		ll a, b; cin >> a >> b;
		mask[a] += b;
	}

	for (i = 0; i < N; i++) {
		auto iter = mask.lower_bound(money[i].first);
		if (iter != mask.end() && iter->first <= money[i].second) {
			if (--iter->second == 0) {
				mask.erase(iter->first);
			}
			ans++;
		}
	}

	cout << ans << ENDL;

	return 0;
}
