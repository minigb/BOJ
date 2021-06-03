//May 26, 2021
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

struct compby {
    bool operator() (const pair<int, int> a, const pair<int, int> b) {
        return a.second > b.second;
    }
};

pair<int, vector<int>> Solution(const vector<vector<pair<int, int>>>& graph, const int n, const int start, const int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compby> pq;
    vector<int> min_distance(n + 1, INT_MAX);
    vector<int> is_from(n + 1, -1);

    min_distance[start] = 0;
    pq.push(make_pair(start, 0));
    while (!pq.empty()) {
        const int current = pq.top().first;
        const int distance = pq.top().second;
        pq.pop();

        if (min_distance[current] < distance) {
            continue;
        }

        for (const pair<int, int>& next_node : graph[current]) {
            if (min_distance[next_node.first] > distance + next_node.second) {
                min_distance[next_node.first] = distance + next_node.second;
                pq.push({ next_node.first, min_distance[next_node.first] });
                is_from[next_node.first] = current;
            }
        }
    }

    vector<int> path = {};
    for (int current = end; current != -1; current = is_from[current]) {
        path.push_back(current);
    }

    reverse(path.begin(), path.end());
    return make_pair(min_distance[end], path);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
    }
    int start, end; cin >> start >> end;

    pair<int, vector<int>> answer = Solution(graph, n, start, end);
    cout << answer.first << kEndl;
    cout << answer.second.size() << kEndl;
    for (const int& node : answer.second) {
        cout << node << ' ';
    }
    cout << kEndl;

    return 0;
}
