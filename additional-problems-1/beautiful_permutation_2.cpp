#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll n;
vector<ll> path;
vector<bool> visited;

void solve() {
  if ((int)path.size() == n) {
    for (int i = 0; i < n; i++)
      cout << path[i] << ' ';
    cout << '\n';
    exit(0);
  }
  for (int next = 1; next <= n; next++) {
    if (visited[next - 1])
      continue;
    if (!path.empty() && abs(path[(int)path.size() - 1] - next) == 1)
      continue;
    path.push_back(next);
    visited[next - 1] = true;
    solve();
    visited[next - 1] = false;
    path.pop_back();
  }
}

int main() {
  cin >> n;
  for (ll i = 0; i < n; i++)
    visited.push_back(false);
  solve();
  cout << "NO SOLUTION\n";
  return 0;
}
