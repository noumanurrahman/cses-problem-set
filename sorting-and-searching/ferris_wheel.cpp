#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  ll answer = 0;
  ll i = 0;
  ll j = n - 1;
  while (i <= j) {
    if (i == j) {
      answer++;
      break;
    }
    ll light = v[i];
    ll heavy = v[j];
    if (light + heavy <= x) {
      i++;
    }
    j--;
    answer++;
  }
  cout << answer << '\n';
}
