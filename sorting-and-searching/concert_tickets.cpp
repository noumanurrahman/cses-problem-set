#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  multiset<ll> tickets;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    tickets.insert(t);
  }
  for (int i = 0; i < m; i++) {
    ll c;
    cin >> c;
    auto it = tickets.upper_bound(c);
    if (it == tickets.begin()) {
      cout << -1 << '\n';
      continue;
    }
    --it;
    cout << *it << '\n';
    tickets.erase(it);
  }
}
