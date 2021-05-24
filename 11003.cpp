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

vector<int> Solution(const vector<int>& arr, const int n, const int l) {
	vector<int> answer(n);
	deque<pair<int, int>> deq;
	for (int right = 0; right < n; right++) { //left : (i-l+1, 0)
		int left = max(right - l + 1, 0);
		while (!deq.empty() && deq.front().second < left) {
			deq.pop_front();
		}
		while (!deq.empty() && deq.back().first >= arr[right]) {
			deq.pop_back();
		}

		deq.push_back({ arr[right], right });

		answer[right] = deq.front().first;
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, l; cin >> n >> l;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> answer = Solution(arr, n, l);
	for (int number : answer) {
		cout << number << ' ';
	}
}
