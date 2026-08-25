#include <iostream>

using namespace std;

void solve(long n) {
  cout << n << " ";
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = (n * 3) + 1;
    }
    if (n == 1) {
      cout << n << "\n";
    } else {
      cout << n << " ";
    }
  }
}

int main() {
  long n;
  cin >> n;
  solve(n);
  return 0;
}
