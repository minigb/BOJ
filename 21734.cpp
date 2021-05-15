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
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int n = (int)s[i];
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		while (sum--) {
			cout << s[i];
		}
		cout << ENDL;
	}
	return 0;
}
