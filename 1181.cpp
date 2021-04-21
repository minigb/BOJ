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
//공백 포함해서 문자열 받기: getline(cin, s);

bool sortby(string, string);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	int i;

	cin >> N;
	vector<string> arr(N);
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), sortby);
	cout << arr[0] << '\n';
	for (i = 1; i < N; i++) {
		if (arr[i] != arr[i - 1]) {
			cout << arr[i] << '\n';
		}
	}

	return 0;
}

bool sortby(string a, string b)
{
	if (a.length() == b.length()) {
		for (int i = 0; a[i]; i++) {
			if (a[i] == b[i]) {
				continue;
			}
			return a[i] < b[i];
		}
	}
	return a.length() < b.length();
}
