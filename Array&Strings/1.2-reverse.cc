#include <iostream>
#include <string>
using namespace::std;

/* reverse a null-terminated string */

void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

void reversed1(char *str) {
	int len = strlen(str);
	int midlen = len / 2;

	for (int i = 0; i < midlen; ++i) {
		swap(str[i], str[len - i - 1]);
	}
}


void reversed2(char *str) {
	if (!str) return;		// empty string

	char *ptrEnd = str;
	while (*ptrEnd) ptrEnd++;
	ptrEnd--;

	while (str < ptrEnd) {
		swap(*str, *ptrEnd);
		str++;
		ptrEnd--;
	}

}

int main() {
	char str[] = "reverse me";
	reversed1(str);
	reversed2(str);
	cout << str << endl;	// should be equivalent to the original string
}
