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

const int NMAX = 202020;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int cnt = 0, ans = 0;

	int cur;
	cin >> cur;
	n--;
	while (n--) {
		int temp; cin >> temp;
		if (cur > temp) cnt++;
		else {
			cur = temp;
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);

	cout << ans;

	return 0;
}
