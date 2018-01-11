#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace::std;

/* Decide if one string is a permutation of the other */

bool isPermutation1(string a, string b) {

	int len = a.length();

	if (len != b.length()) return false;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < len; ++i) {
		if (a[i] != b[i]) return false;
	}

	return true;
}

bool isPermutation2(string a, string b) {
	map<char, int> record;

	int len = a.length();
	if (len != b.length()) return false;

	for (char c : a) record[c]++;
	for (char c : b) {
		record[c]--;
		if (record[c] < 0) return false;
	}

	return true;
}

int main() {
	string a, b;
	cin >> a >> b;

	if (isPermutation1(a, b)) cout << "A is a permutation of B." << endl;
	else cout << "A is not a permutation of B." << endl;

	if (isPermutation2(a, b)) cout << "A is a permutation of B." << endl;
	else cout << "A is not a permutation of B." << endl;
}
