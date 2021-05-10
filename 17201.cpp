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
	string s; cin >> s;
	bool ans = true;
	for (int i = 0; i < n * 2; i += 2) {
		if (s[i] != s[i % 2]) {
			ans = false; break;
		}
	}
	if (ans) cout << "Yes" << ENDL;
	else cout << "No" << ENDL;
	return 0;
}
