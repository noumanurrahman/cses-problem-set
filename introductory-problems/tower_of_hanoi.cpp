#include <iostream>
using namespace std;

void solve(int n, int a, int b, int c) {
  if (n == 1) {
    cout << 1 << " " << 3 << '\n';
  } else if (n == 2) {
    cout << a << " " << c << '\n';
    cout << a << " " << b << '\n';
    cout << c << " " << b << '\n';
  } else {
    solve(n - 1, a, c, b);
    cout << a << " " << b << '\n';
    solve(n - 1, c, b, a);
  }
}

int main() {
  int n;
  cin >> n;
  int k = (1 << n) - 1;
  cout << k << '\n';
  solve(n, 1, 3, 2);
}
