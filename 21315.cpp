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

void Shift(vector<int>& arr, int pow2k) {
	if (pow2k < 1) {
		return;
	}

	int n = arr.size();	
	vector<int> next;
	for (int i = n - pow2k; i < n; i++) {
		next.push_back(arr[i]);
	}
	for (int i = 0; i < n - pow2k; i++) {
		next.push_back(arr[i]);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = next[i];
	}

	for (pow2k /= 2; pow2k >= 1; pow2k /= 2) {
		for (int cur = 0; cur < pow2k; cur++) {
			swap(arr[cur], arr[cur + pow2k]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> result(n);
	for (int i = 0; i < n; i++) {
		cin >> result[i];
	}
	vector<int> pow2 = { 1 };
	for (int i = 1; pow2[i - 1] < n; i++) {
		pow2.push_back(pow2[i - 1] * 2);
	}

	pair<int, int> answer = { -1, -1 };
	for (int k1 = 1; pow2[k1] < n; k1++) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			arr[i] = i + 1;
		}

		Shift(arr, pow2[k1]);
		for (int k2 = 1; pow2[k2] < n; k2++) {
			vector<int> temp = arr;
			Shift(temp, pow2[k2]);

			if (temp == result) {
				answer = { k1, k2 };
			}
		}

		if (answer.first != -1) {
			break;
		}
	}

	cout << answer.first << ' ' << answer.second << kEndl;
}
