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
	ll ans = 0;

	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < n - i; j++) {
			ans += (s[i] - 'a') * pow(26, j);
		}
		ans++;
	}
	
	cout << ans << ENDL;
	
	return 0;
}
