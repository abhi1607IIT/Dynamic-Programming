#include <iostream>
using namespace std;

int lcsB(char* s1, char* s2, int** out) {
	int m = strlen(s1);
	int n = strlen(s2);
	if (m == 0 || n == 0) {
		return 0;
	}
	if (out[m][n] >= 0) {
		return out[m][n];
	}

	if (s1[0] == s2[0]) {
		out[m][n] =  1 + lcsB(s1 + 1, s2 + 1, out);
	} else {
		out[m][n] =  max(lcsB(s1, s2 + 1, out), lcsB(s1 + 1, s2, out));
	}
	return out[m][n];
}

int lcsI(char* s1, char * s2) {
	int m = strlen(s1);
	int n = strlen(s2);
	if (m == 0 || n == 0) {
		return 0;
	}
	int** out = new int*[m + 1];
	for(int i = 0; i <= m; i++) {
		out[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; i++) {
		out[i][0] = 0;
	}
	
	for (int j = 0; j <= n; j++) {
		out[0][j] = 0;
	}
	
	for (int i = 1; i<= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[m - i] == s2[n - j]) {
				out[i][j] = 1 + out[i - 1][j - 1];
			} else {
				out[i][j] = max(out[i][j - 1], out[i - 1][j]);
			}
		}
	}
	return out[m][n];
}

int lcs(char* s1, char* s2) {
	int m = strlen(s1);
	int n = strlen(s2);

	if (m == 0 || n == 0) {
		return 0;
	}

	if (s1[0] == s2[0]) {
		return 1 + lcs(s1 + 1, s2 + 1);
	} else {
		return max(lcs(s1, s2 + 1), lcs(s1 + 1, s2));
	}
}

int main() {
	char s1[] = ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
	char s2[] = "a12bhfiegia12bhfiegia12bhfiegia12bhfiegia12bhfiegia12bhfiegia12bhfiegia12bhfiegi";
	int m = strlen(s1);
	int n = strlen(s2);
	int ** out = new int*[m + 1];
	for(int i = 0; i <= m; i++) {
		out[i] = new int[n + 1];
		for (int j = 0; j <= n; j++) {
			out[i][j] = -1;
		}
	}
	cout << lcsB(s1, s2, out) << endl;
	cout << lcs(s1, s2) << endl;
}

