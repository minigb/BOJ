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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, h, t; cin >> n >> h >> t;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		pq.push(input);
	}

	pair<string, int> ans = { "NO", -1 };
	for (int i = 0; i < t; i++) { //현재 뿅망치를 i번 때린 상태
		int max_height = pq.top();
		pq.pop();

		if (max_height < h) { //키가 가장 큰 사람이 센티보다 작을 때, 모든 사람이 센티보다 작음
			ans = { "YES", i };
			break;
		}
		else { //뿅망치를 때린다
			max_height = max(max_height / 2, 1); //키가 1일 때는 더 이상 줄어들지 않는다는 점 주의
			pq.push(max_height);
		}
	}

	if (ans.first == "NO" && pq.top() < h) { //뿅망치를 t번 치고 난 후의 결과 확인
		ans = { "YES", t };
	}
	
	if (ans.first == "NO") { //불가능할 경우 가장 큰 사람의 키를 출력해야 함
		ans.second = pq.top();
	}

	cout << ans.first << kEndl;
	cout << ans.second << kEndl;
}
