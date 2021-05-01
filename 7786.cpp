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

ll ans[10];

void Count(ll n, ll digit) {
	while (n) {
		ans[n % 10] += digit;
		n /= 10;
	}
}

void Solve(ll a, ll b, ll digit) {
	while (a % 10 != 0 && a <= b) {
		Count(a, digit);
		a++;
	}
	while (b % 10 != 9 && a <= b) {
		Count(b, digit);
		b--;
	}

	if (a > b) {
		return;
	}

	a /= 10; b /= 10;
	for (int i = 0; i < 10; i++) {
		ans[i] += (b - a + 1) * digit;
	}

	Solve(a, b, digit * 10);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll l, u; cin >> l >> u;

	Solve(l, u, 1);

	ll sum = 0;
	for (ll i = 0; i < 10; i++) {
		sum += i * ans[i];
	}
	cout << sum << ENDL;

	return 0;
}
