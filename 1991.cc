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

char IndexToUpper(int n) {
	return (char)('A' + n);
}

void preorder(vector<pair<int, int>>& tree, int cur) {
	cout << IndexToUpper(cur);
	if (tree[cur].first != -1) {
		preorder(tree, tree[cur].first);
	}
	if (tree[cur].second != -1) {
		preorder(tree, tree[cur].second);
	}
}

void inorder(vector<pair<int, int>>& tree, int cur) {
	if (tree[cur].first != -1) {
		inorder(tree, tree[cur].first);
	}
	cout << IndexToUpper(cur);
	if (tree[cur].second != -1) {
		inorder(tree, tree[cur].second);
	}
}

void postorder(vector<pair<int, int>>& tree, int cur) {
	if (tree[cur].first != -1) {
		postorder(tree, tree[cur].first);
	}
	if (tree[cur].second != -1) {
		postorder(tree, tree[cur].second);
	}
	cout << IndexToUpper(cur);
}

int main()
{
	int n; cin >> n;
	vector<pair<int, int>> tree(n, { -1, -1 });
	for (int i = 0; i < n; i++) {
		char parent, child1, child2; cin >> parent >> child1 >> child2;
		if (child1 != '.') {
			tree[parent - 'A'].first = child1 - 'A';
		}
		if (child2 != '.') {
			tree[parent - 'A'].second = child2 - 'A';
		}
	}
	preorder(tree, 0); cout << kEndl;
	inorder(tree, 0); cout << kEndl;
	postorder(tree, 0); cout << kEndl;
}
