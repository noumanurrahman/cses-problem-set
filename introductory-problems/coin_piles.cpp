#include <iostream>
using namespace std;

typedef long long ll;

void solve(ll a, ll b) {
  int sum = a + b;
  if (a > 2 * b || b > 2 * a) {
    cout << "NO\n";
    return;
  }
  if (sum % 3 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  int max_t;
  cin >> max_t;
  for (int t = 1; t <= max_t; t++) {
    ll a, b;
    cin >> a >> b;
    solve(a, b);
  }
}
