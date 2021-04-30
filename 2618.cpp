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
#define ENDL '\n'
#define PI acos(-1)

vector<pair<int, int>> arr;
vector<vector<int>> dp;
int W;

int getDist(pair<int, int> a, pair<int, int> b);
int solve(int, int);
void print(int, int);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int i;

	cin >> N >> W;
	arr.resize(W + 5);
	arr[1] = { 1, 1 };
	arr[2] = { N, N };
	for (i = 3; i <= W + 2; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	dp.resize(W + 5, vector<int> (W + 5, -1));
	cout << solve(1, 2) << ENDL;
	print(1, 2);	

	return 0;
}

int getDist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int car1, int car2)
{
	int cur = max(car1, car2);
	if (cur == W + 2) {
		return 0;
	}

	if (dp[car1][car2] != -1) {
		return dp[car1][car2];
	}
	
	dp[car1][car2] = 0;
	int case1 = solve(cur + 1, car2) + getDist(arr[car1], arr[cur + 1]);
	int case2 = solve(car1, cur + 1) + getDist(arr[car2], arr[cur + 1]);

	return dp[car1][car2] = min(case1, case2);
}

void print(int car1, int car2)
{
	int cur = max(car1, car2);
	if (cur == W + 2) {
		return;
	}

	int case1 = solve(cur + 1, car2) + getDist(arr[car1], arr[cur + 1]);
	int case2 = solve(car1, cur + 1) + getDist(arr[car2], arr[cur + 1]);

	if (dp[car1][car2] == case1) {
		cout << 1 << ENDL;
		return print(cur + 1, car2);
	}
	else {
		cout << 2 << ENDL;
		return print(car1, cur + 1);
	}
}
