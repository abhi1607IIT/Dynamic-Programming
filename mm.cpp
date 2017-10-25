#include <iostream>
using namespace std;

int mm(int * a, int s, int e, int** out) {
	if (s >= e) {
		return 0;
	}
	if (out[s][e] > 0) {
		return out[s][e];
	}
	int minOperation = INT_MAX;
	for (int i = s; i < e; i++) {
		int leftMultiplication = mm(a, s, i);
		int rightMultiplication = mm(a, i + 1, e);
		int finalMultiplication = a[s - 1] * a[i] * a[e];
		if (leftMultiplication + rightMultiplication + 
				finalMultiplication < minOperation) {
			minOperation = leftMultiplication + rightMultiplication +
				finalMultiplication;
		}
	}
	out[si][ei] = minOperation;
	return minOperation;
}

int main() {
	int a[] = {10, 50, 100, 200};
	cout << mm(a, 1, 3) << endl;
}

