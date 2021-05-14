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
	int h, w, x, y; cin >> h >> w >> x >> y;
	vector<vector<int>> b(h + x, vector<int>(w + y));
	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			cin >> b[i][j];
		}
	}

	vector<vector<int>> a(h, vector<int>(w, -1));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!((x <= i && i < h) && (y <= j && j < w))) {
				a[i][j] = b[i][j];
			}
			if (!((0 <= i && i < h - x) && (0 <= j && j < w - y))) {
				a[i][j] = b[i + x][j + y];
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == -1) {
				a[i][j] = b[i][j] - a[i - x][j - y];
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j] << ' ';
		}
		cout << ENDL;
	}

	return 0;
}
