#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  ll curr_sum = v[0];
  ll max_sum = v[0];
  for (int i = 1; i < n; i++) {
    curr_sum = max(v[i], v[i] + curr_sum);
    max_sum = max(max_sum, curr_sum);
  }
  cout << max_sum << '\n';
}
