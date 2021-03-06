#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }

  sort(arr.begin(), arr.end());

  int ans = abs(arr[0] - arr[1]);
  for (int i = 1; i < arr.size(); i++) {
    if (abs(arr[i] - arr[i - 1]) < ans) {
      ans = abs(arr[i] - arr[i - 1]);
    }
  }

  cout << ans;

  return 0;
}
