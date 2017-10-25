#include <iostream>
using namespace std;

int maxSum(int * a, int size) {
	if (size <= 0) {
		return 0;
	}
	int opt1 = maxSum(a + 1, size -1);
	int opt2 = maxSum(a + 2, size - 2) + a[0];
	return max(opt1, opt2);
}

int maxSum2(int* a, int size) {
	if (size == 0) {
		return 0;
	}
	if (size == 1) {
		return a[0];
	}
	int * out = new int[size];
	out[size - 1] = a[size - 1];
	out[size - 2] = max(a[size - 1], a[size - 2]);

	for (int i = size - 3; i >= 0; i--) {
		out[i] = max(out[i + 1], a[i] + out[i + 2]);
	}
	int output = out[0];
	delete [] out;
	return output;
}

int maxSum(int * a, int size, int * out) {
	if (size <= 0) {
		return 0;
	}

	if (out[size] > 0) {
		return out[size];
	}
	int opt1 = maxSum(a + 1, size -1, out);
	int opt2 = maxSum(a + 2, size - 2, out) + a[0];
	out[size] = max(opt1, opt2);
	return out[size];
}

int main() {
	
}

