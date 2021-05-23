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
const char kEndl = '\n';
const double kPi = acos(-1);

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input; cin >> input;
			if (pq.size() < n) {
				pq.push(input);
			}
			else {
				if (pq.top() < input) {
					pq.pop();
					pq.push(input);
				}
			}
		}
	}

	cout << pq.top() << kEndl;

}
