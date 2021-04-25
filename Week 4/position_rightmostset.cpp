#include <iostream>
#include <math.h>
using namespace std;
class gfg
{
public:
unsigned int getFirstSetBitPos(int n)
{
	return log2(n & -n) + 1;
}
};
int main()
{
	gfg g;
	int n = 12;
	cout << g.getFirstSetBitPos(n);
	return 0;
}


