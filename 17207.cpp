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
	vector<string> name = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
	int n = 5;
	vector<vector<ll>> a(n, vector<ll>(n)), b(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> b[i][j];
	}

	vector<ll> sum(n);
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int i = 0; i < n; i++) {
				sum[x] += a[x][i] * b[i][y];
			}
		}
	}

	ll minSum = LLONG_MAX;
	int idx;
	for (int i = 0; i < n; i++) {
		if (minSum >= sum[i]) {
			minSum = sum[i];
			idx = i;
		}
	}

	cout << name[idx] << ENDL;
	
	return 0;
}
