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
	vector<int> arr(n + 5);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	deque<int> deq;
	for (int i = 1; i <= n; i++) deq.push_back(i);

	while (!deq.empty()) {
		int move = arr[deq.front()];
		cout << deq.front() << ' ';
		deq.pop_front();

		if (deq.empty()) break;
		if (move > 0) {
			move--;
			while (move--) {
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else {
			move *= -1;
			while (move--) {
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}

	return 0;
}
