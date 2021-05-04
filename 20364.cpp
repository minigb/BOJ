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
using namespace std;
typedef long long ll;
const int int_inf = 2147483646;
const ll ll_inf = 9223372036854775806;
#define PI 3.141592653589793238462643383279502
//소수점 출력
//cout << fixed << setprecision(10) << ans << '\n'. setprecision은 iomanip 라이브러리에 있음
//공백 포함해서 문자열 받기: getline(cin, s);

vector<bool> chk;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, Q;
	int cur, togo;
	int ans;
	int i;

	cin >> N >> Q;
	chk.resize(N + 5, false);

	for (i = 0; i < Q; i++) {
		cin >> togo;
		cur = togo;
		ans = -1;
		while (cur) {
			if (chk[cur]) {
				ans = cur;
			}
			cur /= 2;
		}

		if (ans == -1) {
			chk[togo] = true;
			cout << 0 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}

	return 0;
}
