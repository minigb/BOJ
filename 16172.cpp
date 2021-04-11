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

class KMP {
public:
	string str, pat;
	vector<int> table;
	vector<int> ans;
		
	void getTable() {
		table.resize(pat.length());
		int left = 0;
		for (int i = 1; i < pat.length(); i++) {
			while (left > 0 && pat[left] != pat[i]) {
				left = table[left - 1];
			}
			if (pat[left] == pat[i]) {
				table[i] = left + 1;
				left++;
			}
		}
	}

	void getAns() {
		getTable();
		int patIdx = 0;
		for (int strIdx = 0; strIdx < str.length(); strIdx++) {
			while (patIdx > 0 && pat[patIdx] != str[strIdx]) {
				patIdx = table[patIdx - 1];
			}
			if (pat[patIdx] == str[strIdx]) {
				if (patIdx == pat.length() - 1) {
					ans.push_back(strIdx - pat.length() + 1);
					patIdx = table[patIdx];
				}
				else {
					patIdx++;
				}
			}
		}
	}
};

int main() {
	KMP kmp;
	string a; cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (!('0' <= a[i] && a[i] <= '9')) {
			kmp.str += a[i];
		}
	}
	cin >> kmp.pat;

	kmp.getAns();

	cout << (kmp.ans.size() ? 1 : 0) << ENDL;
}
