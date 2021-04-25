#include <iostream>
#include <vector>
using namespace std;
#define MAX N

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M, N;
	int i, j;

	cin >> M >> N;

	vector<int> primeNums; //소수들 저장
	vector<bool> isPrime(MAX + 1, true); //isPrime[i]에는 i가 소수인지의 여부가 저장되어 있음
	isPrime[0] = isPrime[1] = false;

	for (i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			primeNums.push_back(i);
			for (j = i * 2; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (i = 0; i < primeNums.size() && primeNums[i] < M; i++);
	for (; i < primeNums.size(); i++) {
		cout << primeNums[i] << '\n';
	}

	return 0;
}
