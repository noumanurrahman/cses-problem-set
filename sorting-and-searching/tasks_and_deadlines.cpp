#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> tasks(n);
  for (int i = 0; i < n; i++) {
    ll a, d;
    cin >> a >> d;
    tasks[i] = {a, d};
  }
  sort(tasks.begin(), tasks.end());
  ll t = 0;
  ll reward = 0;
  for (const auto &task : tasks) {
    t += task.first;
    reward += task.second - t;
  }
  cout << reward << '\n';
}
