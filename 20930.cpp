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

const int NMAX = 2e5 + 10;
vector<int> par(NMAX, -1);
void merge(int, int);
int getPar(int);

int n;
class Cordinate {
public:
	int start, end, number;

	Cordinate() {}
	Cordinate(int a, int b, int c) {
		if (a > b) swap(a, b);
		start = a;
		end = b;
		number = c;
	}
	bool operator < (Cordinate next) {
		if (start < next.start) return true;
		if (next.start < start) return false;
		return end < next.end;
	}
};

void sol(vector<Cordinate>& arr) {
	sort(arr.begin(), arr.end());
	Cordinate cur = arr[0];

	for (int i = 0; i < n; i++) {
		if (!(cur.end < arr[i].start)) {
			merge(cur.number, arr[i].number);
			cur.end = max(cur.end, arr[i].end);
		}
		else {
			cur = arr[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	vector<Cordinate> x, y;

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		x.push_back(Cordinate(x1, x2, i + 1));
		y.push_back(Cordinate(y1, y2, i + 1));
	}

	sol(x);
	sol(y);

	while (q--) {
		int a, b; cin >> a >> b;
		cout << (int)(getPar(a) == getPar(b)) << ENDL;
	}

	return 0;
}

void merge(int a, int b)
{
	a = getPar(a);
	b = getPar(b);

	if (a != b) {
		par[a] = b;
	}
}

int getPar(int n)
{
	if (par[n] == -1) return n;
	return par[n] = getPar(par[n]);
}
