#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y;
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string whatDay[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int cnt;
	int i;

	cin >> x >> y;
	cnt = 0;
	for (i = 1; i <= x - 1; i++) {
		cnt += days[i];
	}
	cnt += y;

	cout << whatDay[cnt % 7] << '\n';

	return 0;
}
