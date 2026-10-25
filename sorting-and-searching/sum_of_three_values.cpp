#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<pair<ll, int>> nums(n);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    nums[i] = {a, i};
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++) {
    int j = 0;
    int k = n - 1;
    while (j < k) {
      if (j == i) {
        j++;
      }
      if (k == i) {
        k--;
      }
      if (j == k)
        break;
      ll s = nums[i].first + nums[j].first + nums[k].first;
      if (s == x) {
        cout << nums[i].second + 1 << ' ';
        cout << nums[j].second + 1 << ' ';
        cout << nums[k].second + 1 << '\n';
        return 0;
      } else if (s > x) {
        k--;
      } else {
        j++;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
