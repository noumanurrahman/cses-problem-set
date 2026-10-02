#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  set<ll> s;
  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    s.insert(a);
  }
  cout << (int)s.size() << '\n';
}
