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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll input;
	ll cnt;
	ll n = 1;

	cin >> input;

	vector<ll> chilli;
	chilli.push_back(0);

	for (ll n = 1; ; n *= 7) {
		ll size = chilli.size();
		for (ll i = 0; i < size; i++) {
			chilli.push_back(chilli[i] + n);
		}
		for (ll i = 0; i < size; i++) {
			chilli.push_back(chilli[i] + n * 2);
		}

		if (binary_search(chilli.begin(), chilli.end(), input)) {
			cout << lower_bound(chilli.begin(), chilli.end(), input) - chilli.begin();
			break;
		}
	}

	return 0;
}
