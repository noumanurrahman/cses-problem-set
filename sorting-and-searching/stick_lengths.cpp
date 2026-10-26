#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> sticks(n);
  for (int i = 0; i < n; i++)
    cin >> sticks[i];
  sort(sticks.begin(), sticks.end());
  ll x = 0;
  if (n % 2 == 0) {
    x = (sticks[n / 2] + sticks[(n / 2) - 1]) / 2;
  } else {
    x = sticks[n / 2];
  }
  ll answer = 0;
  for (int i = 0; i < n; i++) {
    answer += abs(x - sticks[i]);
  }
  cout << answer << '\n';
}
