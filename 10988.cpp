#include <iostream>
using namespace std;

bool palin(int left, int right, string& s) {
	if (!(left <= right)) {
		return true;
	}

	if (s[left] != s[right]) {
		return false;
	}
	else {
		return palin(left + 1, right - 1, s);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;

	cout << palin(0, s.length() - 1, s);

	return 0;
}
