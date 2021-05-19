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

void dfs(vector<vector<int>>& child, vector<int>& cnt, int cur) {
	if (child[cur].size() == 0) {	//기저 조건: 리프 노드일 경우
		cnt[cur] = 1;				//리프 노드 개수 1
		return;
	}

	for (int next : child[cur]) {
		dfs(child, cnt, next);		//리프 노드까지 도달
		cnt[cur] += cnt[next];		//개수 더해주기
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> parent(n);
	vector<vector<int>> child(n);
	int root = -1;
	for (int i = 0; i < n; i++) {
		cin >> parent[i];
		if (parent[i] == -1) {
			root = i;
		}
		else {
			child[parent[i]].push_back(i);
		}
	}

	vector<int> cnt(n, 0);
	dfs(child, cnt, root);

	int erase; cin >> erase;
	if (erase == root) {		//루트 노드를 지우면 트리에 노드 자체가 남아있지 않음
		cout << 0 << kEndl;
	}
	else {						
		if (child[parent[erase]].size() == 1) {	//지워지는 노드가 부모의 유일한 자식일 때
			cout << cnt[root] - cnt[erase] + 1 << kEndl;	//노드가 지워지면서 또 다른 리프노드 생성
		}
		else {
			cout << cnt[root] - cnt[erase] << kEndl;
		}		
	}
}
