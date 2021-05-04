#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#define PI 3.141592653589793238462643383279502
//소수점 출력
//cout << fixed << setprecision(10) << ans << '\n'. setprecision은 iomanip 라이브러리에 있음
#define MOD 15746
vector<vector<int>> dp;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int i, j;

	cin >> N;
	vector<int> arr(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> inc(N, 1), dec(N, 1);

	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				inc[i] = max(inc[i], inc[j] + 1);
			}
		}
	}

	for (i = N - 1; i >= 0; i--) {
		for (j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				dec[i] = max(dec[i], dec[j] + 1);
			}
		}
	}

	int ans = 0;
	for (i = 0; i < N; i++) {
		ans = max(ans, inc[i] + dec[i] - 1);
	}

	cout << ans << '\n';
	
	return 0;
}
