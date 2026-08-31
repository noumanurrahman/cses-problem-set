#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long y, x;
    cin >> y >> x;

    long long n = max(y, x);
    long long answer;

    if (n % 2 == 1) {
      // n is odd
      if (x == n) {
        answer = n * n - y + 1;
      } else {
        answer = (n - 1) * (n - 1) + x;
      }
    } else {
      // n is even
      if (y == n) {
        answer = n * n - x + 1;
      } else {
        answer = (n - 1) * (n - 1) + y;
      }
    }

    cout << answer << '\n';
  }

  return 0;
}
