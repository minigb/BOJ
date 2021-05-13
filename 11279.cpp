#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define ENDL '\n'
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using namespace std;

template<typename T>
class Heap {
public:
	Heap<T>() {
		end = 1;
		tree.resize(1);
	}

	virtual void push(T value) = 0;
	virtual void pop() = 0;

	T top() {
		return tree[1];
	}

	bool empty() {
		return end == 1;
	}

	ull size() {
		return end;
    }
    
protected:
	vector<T> tree;
	ull end;
};

template<typename T>
class MaxHeap : public Heap<T> {
public:
	virtual void push(T value) {
		if (this->end == this->tree.size()) {
			this->tree.resize(this->tree.size() * 2);
		}
		this->tree[this->end++] = value;

		for (ull child = this->end - 1; child >= 1; child /= 2) {
			ull parent = child / 2;
			if (parent >= 1 && this->tree[parent] < this->tree[child]) {
				swap(this->tree[parent], this->tree[child]);
			}
			else {
				break;
			}
		}
	}
	
	virtual void pop() {
		this->tree[1] = this->tree[this->end - 1];
		this->end--;

		for (ull parent = 1; parent * 2 < this->end; ) {
			ull largerChild;
			if (parent * 2 + 1 < this->end) {
				largerChild = parent * 2 + (this->tree[parent * 2] > this->tree[parent * 2 + 1] ? 0 : 1);				
			}
			else {
				largerChild = parent * 2;
			}

			if (this->tree[largerChild] > this->tree[parent]) {
				swap(this->tree[parent], this->tree[largerChild]);
				parent = largerChild;
			}
			else {
				break;
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	MaxHeap<int> maxHeap;
	int n; cin >> n;
	while (n--) {
		int input; cin >> input;
		if (input == 0) {
			if (maxHeap.empty()) {
				cout << 0 << ENDL;
			}
			else {
				cout << maxHeap.top() << ENDL;
				maxHeap.pop();
			}
		}
		else {
			maxHeap.push(input);
		}
	}
}
