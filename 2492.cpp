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

/*
width: 5, height: 5
t: 3
k: 3
(5, 0), (5, 1), (5, 2)
*/
pair<pair<int, int>, int> Solution(const int width, const int height, const int t, const int k, vector<pair<int, int>> jewels) {
    pair<int, int> answer_cordinate = make_pair(-1, -1);
    int answer_jewel = 0;
    sort(jewels.begin(), jewels.end()); //1. increasing order of x, 2. if x is same, increasing order of y

    //O(T^2)
    //x_start: 2, x_end: 5
    //y_start: 2, y_end: 5
    for (int i = 0; i < jewels.size(); ++i) {
        int x_start = jewels[i].first;
        for (int j = 0; j < jewels.size(); ++j) {
            int y_start = jewels[j].second;
            int x_end = min(x_start + k, width);
            int y_end = min(y_start + k, height);

            x_start = x_end - k;
            y_start = y_end - k;

        //index: [0, 3)
        int start_index = lower_bound(jewels.begin(), jewels.end(), make_pair(x_start, y_start)) - jewels.begin(); //[0, 4)
        int end_index = upper_bound(jewels.begin(), jewels.end(), make_pair(x_end, y_end)) - jewels.begin();

        int count = 0;
        for (int k = start_index; k < end_index; ++k) {
            if (y_start <= jewels[k].second && jewels[k].second <= y_end) {
                ++count;
            }
        }

        if (count > answer_jewel) {
            answer_cordinate = { x_start, y_end };
            answer_jewel = count;
        }
        }
    }

    return { answer_cordinate, answer_jewel };
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, t, k; cin >> n >> m >> t >> k;
    vector<pair<int, int>> arr(t);
    for (int i = 0; i < t; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    pair<pair<int, int>, int> answer = Solution(n, m, t, k, arr);
    cout << answer.first.first << ' ' << answer.first.second << kEndl;
    cout << answer.second << kEndl;

    return 0;
}
