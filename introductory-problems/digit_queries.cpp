#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

void solve(ll k) {
  ll skipped = 0;
  ll e = 9;
  for (ll l = 1; true; l++) {
    if (k > e * l) {
      k -= e * l;
      skipped += e;
    } else {
      ll skip = (k - 1) / l;
      skipped += skip;
      k -= skip * l;
      ll x = skipped + 1;
      cout << to_string(x)[k - 1] << '\n';
      return;
    }
    e *= 10;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll k;
    cin >> k;
    solve(k);
  }
}
