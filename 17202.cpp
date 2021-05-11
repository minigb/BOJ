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
	string n1, n2; cin >> n1 >> n2;
	string cur;
	for (int i = 0; i < n1.length(); i++) {
		cur += n1[i];
		cur += n2[i];
	}
	while (cur.length() > 2) {
		string next = "";
		for (int i = 0; i + 1 < cur.length(); i++) {
			int n = (cur[i] - '0') + (cur[i + 1] - '0');
			next += (n % 10) + '0';
		}
		cur = next;
	}
	cout << cur << ENDL;
	return 0;
}
