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
	queue<int> que;
	while (1) {
		int input; cin >> input;
		if (input == -1) break;

		if (input != 0){
			if (que.size() < n) {
				que.push(input);
			}
		}
		else {
			if (!que.empty()) que.pop();
		}
	}

	if (que.empty()) cout << "empty" << ENDL;
	else {
		while (!que.empty()) {
			cout << que.front() << ' ';
			que.pop();
		}
	}
	return 0;
}
