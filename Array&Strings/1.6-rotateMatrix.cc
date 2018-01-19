#include <iostream>
#include <vector>
using namespace::std;

void rotate(vector<vector<int> > &v, int n) {
	int layer = n / 2;
	for (int lay = 0; lay < layer; ++lay) {
		int endpos = n - lay - 1;
		for (int i = lay; i < endpos; ++i) {
			int offset = i - lay;
			int diff = endpos - offset;

			int top = v[lay][i];

			// left to top
			v[lay][i] = v[diff][lay];

			// bottom to left
			v[diff][lay] = v[endpos][diff];

			// right to bottom
			v[endpos][diff] = v[i][endpos];

			// top to right
			v[i][endpos] = top;

		}
	}
}

int main() {
	int size = 6, counter = 0;
	std::vector<std::vector<int> > v(size, std::vector<int>(size));

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			v[i][j] = counter;
			counter++;
		}
	}

	rotate(v, size);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}