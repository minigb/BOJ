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

vector<vector<ll>> arr, sum;
int N, M;

ll getSum(int y, int x)
{
	int yy = max(0, y - M), xx = max(0, x - M);
	
	return sum[y][x] - sum[yy][x] - sum[y][xx] + sum[yy][xx];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, j;

	cin >> N >> M;
	arr.resize(N + 5, vector<ll>(N + 5));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> arr[i][j];
			arr[i][j] *= -1;
		}
	}
	
	//M == 1일때
	if (M == 1) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << ENDL;
		}

		return 0;
	}

	//M != 1일때
	sum.resize(N + 5, vector<ll>(N + 5));
	vector<vector<ll>> ans(N + 5, vector<ll>(N + 5));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

			ll diff = arr[i][j] - getSum(i, j);
			if (diff > 0) {
				sum[i][j] += diff;
				ans[i + M / 2][j + M / 2] += diff;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << ENDL;
	}
	
	return 0;
}
