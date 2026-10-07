#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<pair<ll, int>> v;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    v.push_back({a, i});
  }
  sort(v.begin(), v.end());
  int i = 0;
  int j = n - 1;
  while (i < j) {
    ll sum = v[j].first + v[i].first;
    if (sum == x) {
      cout << v[i].second + 1 << ' ' << v[j].second + 1 << '\n';
      return 0;
    } else if (sum < x) {
      i++;
    } else {
      j--;
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
