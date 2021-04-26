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
#define ENDL '\n'
#define PI acos(-1)

struct Edge {
	int start, end, width;
};

bool sortby(Edge a, Edge b) {
	return a.width > b.width;
}

vector<int> par;
int GetPar(int);
void Merge(int, int);


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int P, W;
	int C, V;

	cin >> P >> W
		>> C >> V;
	vector<Edge> edges(W + 5);
	for (int i = 0; i < W; i++) {
		cin >> edges[i].start >> edges[i].end >> edges[i].width;
	}
	sort(edges.begin(), edges.begin() + W, sortby);

	par.resize(P + 5, -1);

	for (int i = 0; i < W; i++) {
		Merge(edges[i].start, edges[i].end);
		if (GetPar(C) == GetPar(V)) {
			cout << edges[i].width << ENDL;
			break;
		}
	}

	return 0;
}

int GetPar(int x)
{
	if (par[x] == -1) {
		return x;
	}
	return par[x] = GetPar(par[x]);
}

void Merge(int x, int y)
{
	x = GetPar(x);
	y = GetPar(y);
	
	if (x != y) {
		par[x] = y;
	}
}
