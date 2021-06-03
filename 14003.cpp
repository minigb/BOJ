//May 25, 2021
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
const char kEndl = '\n';
const double kPi = acos(-1);

using namespace std;
vector<int> Solution(vector<int> input) {
    if (input.size() == 0) {
        return {};
    }

    const int n = input.size();
    vector<int> index(n);
    vector<int> lis = { input[0] };
    index[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (lis.back() < input[i]) {
            lis.push_back(input[i]);
            index[i] = lis.size() - 1;
        }
        else {
            int lis_index = lower_bound(lis.begin(), lis.end(), input[i]) - lis.begin();
            lis[lis_index] = input[i];
            index[i] = lis_index;
        }
    }

    int lis_length = lis.size();
    vector<int> answer(lis_length);
    int current_index = lis_length - 1;
    for (int i = n - 1; i >= 0 && current_index >= 0; --i) {
        if (index[i] == current_index) {
            answer[current_index--] = input[i];
        }
    }

    return answer;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> answer = Solution(arr);
    cout << answer.size() << kEndl;
    for (const int& num : answer) {
        cout << num << ' ';
    }
    cout << kEndl;
    return 0;
}
