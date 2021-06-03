//May 26, 2021
#include <iostream>
using namespace std;

long long Solution(long long n, long long k) {
    long long answer = 0;
    long long coupon = n, stamp = 0;
    while (1) {
        if (coupon > 0) {
            answer += coupon;
            stamp += coupon;
            coupon = 0;
        }

        if (stamp >= k) {
            coupon += stamp / k;
            stamp %= k;
        }
        else {
            break;
        }
    }

    return answer;
}

int main() {
    int n;
    while (cin >> n) {
        int k; cin >> k;
        cout << Solution(n, k) << '\n';
    }
}
