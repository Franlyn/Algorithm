#include <iostream>
#include <string>
using namespace::std;

/* Replace all spaces in a string with "%20".
   Assume the string has sufficient space at the end of the string.
   The true length of the string should be given, 
   but my implementation assumes it's not given. */

void replaceSpace(char *str) {
	if (str == NULL) return;
	int len = strlen(str);		// include the whitespaces in the end
	if (len == 0) return;

	int spaces = 0;
	bool start = false;
	for (int i = len - 1; i >= 0; --i) {
		if (!start && str[i] != ' ') start = true;
		if (!start) continue;
		if (str[i] == ' ') spaces++;
	}
	cout << spaces << endl;

	int cur = len - spaces * 2;	// include null terminator

	str[len] = '\0';
	len--;
	for (int i = cur - 1; i >= 0; --i) {
		if(str[i] == ' ') {
			str[len] = '0';
			str[len-1] = '2';
			str[len-2] = '%';
			len -= 3;
		} else {
			str[len] = str[i];
			len--;
		}
	}

}
int main() {
	char str[] = "Mr John Smith    ";
	replaceSpace(str);
	cout << str << endl;
}
