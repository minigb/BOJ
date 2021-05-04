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
	string str, bomb; cin >> str >> bomb;
	stack<char> stck;
	for (int i = 0; i < str.length(); i++) {
		stck.push(str[i]);
		if (!stck.empty() && str[i] == bomb.back()) {
			int idx = bomb.length() - 1;
			bool okay = true;
			for (; idx >= 0 && !stck.empty(); idx--) {
				if (stck.top() != bomb[idx]) {
					okay = false; break;
				}
				else {
					stck.pop();
				}
			}
			if (idx >= 0) okay = false;

			if (!okay) {
				for (int i = idx + 1; i < bomb.length(); i++) {
					stck.push(bomb[i]);
				}
			}
		}
	}

	string ans = "";
	while (!stck.empty()) {
		ans += stck.top();
		stck.pop();
	}
	reverse(ans.begin(), ans.end());

	if (ans == "") ans = "FRULA";
	cout << ans << ENDL;

	return 0;
}
