#include <iostream>
using namespace std;

void solve(int n, int a, int b) {
  int free_pos = ((a == 1 && b == 2) || (a == 2 && b == 1))   ? 3
                 : ((a == 1 && b == 3) || (a == 3 && b == 1)) ? 2
                 : ((a == 2 && b == 3) || (a == 3 && b == 2)) ? 1
                                                              : 0;

  if (n == 1) {
    cout << 1 << " " << 3 << '\n';
  } else if (n == 2) {
    cout << a << " " << free_pos << '\n';
    cout << a << " " << b << '\n';
    cout << free_pos << " " << b << '\n';
  } else {
    solve(n - 1, a, free_pos);
    cout << a << " " << b << '\n';
    solve(n - 1, free_pos, b);
  }
}

int main() {
  int n;
  cin >> n;
  int k = (1 << n) - 1;
  cout << k << '\n';
  solve(n, 1, 3);
}
