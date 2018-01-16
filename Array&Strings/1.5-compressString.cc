#include <iostream>
#include <string>
using namespace::std;

/* Implement a method to perform basic string compression 
using the counts of repeated characters. 
For example, the string a a b c c c c c a a a would become a2blc5a3. 
If the "compressed" string would not become smaller than the original string, 
your method should return the original string */

/* Need to come back. This solution is quite buggy */

char* compressed(char *str) {
	if (str == NULL) return str;
	int len = strlen(str);
	if (len == 0) return str;

	int repeated = 0, j = 0;
	char rep[len];
	memset(rep, 0, len);

	rep[0] = str[0];

	for (int i = 0; i < len; ++i) {
		repeated = 1;
		if (rep[j+1] == 0) {
			j++;
			rep[j] = repeated + '0';
		} else {
			return str;
		}

		while (str[i] == str[i+1]) {
			repeated++;
			rep[j] = repeated + '0';
			i++;
		}

		if (rep[j+1] == 0) {
			rep[++j] = str[i+1];
		} else {
			return str;
		}

	}
	j++;
	rep[j] = '0';

	char* newstr = (char*) malloc(sizeof(rep));
	strcpy(newstr, rep);
	return newstr;

}


int main() {
	char str[] = "aabcccccaaa";
	char* newstr = compressed(str);
	cout << newstr << endl;
}
