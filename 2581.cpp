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
using namespace std;

vector<int> primeNums; //소수들 저장
vector<bool> isPrime; //isPrime[i]에는 i가 소수인지의 여부가 저장되어 있음
void era(int MAX)
{
	isPrime.resize(MAX + 1, true);
	int i, j;
	
	isPrime[0] = isPrime[1] = false;

	for (i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			primeNums.push_back(i);
			for (j = i * i; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	int M, N;
	ll ans = 0;
	int min_;
	int i;

	cin >> M >> N;
	era(N);
	
	i = lower_bound(primeNums.begin(), primeNums.end(), M) - primeNums.begin();
	if (i == primeNums.size() || primeNums[i] > N) {
		cout << -1 << '\n';
		return 0;
	}
	
	min_ = primeNums[i];
	for (; i < primeNums.size() && primeNums[i] <= N; i++) {
		ans += primeNums[i];
	}

	cout << ans << '\n';
	cout << min_ << '\n';
}
