#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f[37];

int main() {
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for (int i = 4;i <= 36;i ++) f[i] = f[i-1] + f[i-2] + f[i-3];
    int n;
    cin >> n;
    for (int i = 0;i < n;i ++) {
        int m;
        cin >> m;
        cout << f[m] << endl;
    }
    return 0;
}