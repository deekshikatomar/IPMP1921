#include <bits/stdc++.h>
using namespace std;
int isPowerOfTwo(unsigned n)
{
	return n && (!(n & (n - 1)));
}
int findPosition(unsigned n)
{
	if (!isPowerOfTwo(n))
		return -1;
	unsigned i = 1, pos = 1;
	while (!(i & n)) {

		i = i << 1;
		++pos;
	}
	return pos;
}
int main(void)
{
	int n = 16;
	int pos = findPosition(n);
	(pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
	n = 12;
	pos = findPosition(n);
	(pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;
	n = 128;
	pos = findPosition(n);
	(pos == -1) ? cout << "n = " << n << ", Invalid number" << endl : cout << "n = " << n << ", Position " << pos << endl;

	return 0;
}


