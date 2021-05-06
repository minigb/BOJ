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
	int tc; cin >> tc;
	while (tc--) {
		string s; cin >> s;
		stack<char> stck;
		bool ans = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') stck.push(s[i]);
			else {
				if (stck.empty()) {
					ans = false;
					break;
				}
				else {
					stck.pop();
				}
			}
		}

		if (!stck.empty()) ans = false;

		if (ans) cout << "YES" << ENDL;
		else cout << "NO" << ENDL;
	}
	return 0;
}
