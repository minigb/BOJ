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
	int tc; cin >> tc;
	getchar();
	for (int forTC = 1; forTC <= tc; forTC++) {
		string s; getline(cin, s);
		vector<string> arr = { "" };
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				arr.back() += s[i];
			}
			else {
				arr.push_back("");
			}
		}

		cout << "Case #" << forTC << ": ";
		for (int i = arr.size() - 1; i >= 0; i--) {
			cout << arr[i] << ' ';
		}
		cout << ENDL;
	}
	return 0;
}
