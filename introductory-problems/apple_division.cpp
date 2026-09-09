#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

typedef long long ll;

int n;
ll weights[20];
ll answer = LONG_LONG_MAX;

void solve(int i, ll a, ll b) {
  if (i == n) {
    answer = min(answer, abs(a - b));
    return;
  }
  solve(i + 1, a + weights[i], b);
  solve(i + 1, a, b + weights[i]);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> weights[i];
  }
  solve(0, 0, 0);
  cout << answer << '\n';
}
