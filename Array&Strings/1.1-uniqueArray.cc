#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

/* Implement an algorithm to determine if a string has all unique characters.
  Additional data structures cannot be used.
  I will use map if there is no restrictions */

// check if the string contains all unique characters
// O(n^2)
bool isUnique1(string chars) {
	unsigned int len = chars.size();
	for (unsigned int i = 0; i < len; i++) {
		char cur = chars[i];
		for (unsigned int j = i + 1; j < len; j++) {
			if (cur == chars[j]) return false;
		}
	}
	return true;
}

// O(nlogn)
bool isUnique2(string chars) {
	sort(chars.begin(), chars.end());

	unsigned int len = chars.size();
	for (unsigned int i = 0; i < len - 1; i++) {
		if (chars[i] == chars[i+1]) return false;
	}
	return true;
}

// O(n)
bool isUnique3(string chars) {
	bool bits[256];
	memset(bits, false, sizeof(bits));

	unsigned int len = chars.size();
	for (unsigned int i = 0; i < len; i++) {
		int cur = chars[i];
		if (bits[cur]) return false;
		bits[cur] = true;
	}
	return true;
}

int main() {
	// take input
	string chars;
	cin >> chars;

	bool unique1 = isUnique1(chars);
	bool unique2 = isUnique2(chars);
	bool unique3 = isUnique3(chars);

	if (unique1) cout << "1. unique array." << endl;
	else cout << "1. not an unique array." << endl;

	if (unique2) cout << "2. unique array." << endl;
	else cout << "2. not an unique array." << endl;

	if (unique3) cout << "3. unique array." << endl;
	else cout << "3. not an unique array." << endl;

}
