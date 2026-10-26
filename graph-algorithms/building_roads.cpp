#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> roads(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    roads[a].push_back(b);
    roads[b].push_back(a);
  }
  vector<bool> visited(n, false);
  int components = 0;
  vector<pair<int, int>> new_roads;
  for (int i = 0; i < n; i++) {
    if (visited[i])
      continue;
    components++;
    if (i != 0) {
      new_roads.push_back({i + 1, 1});
    }
    stack<int> st;
    st.push(i);
    while (!st.empty()) {
      int x = st.top();
      st.pop();
      for (const int y : roads[x]) {
        if (visited[y])
          continue;
        st.push(y);
        visited[y] = true;
      }
    }
  }
  cout << components - 1 << '\n';
  for (const auto &road : new_roads)
    cout << road.first << ' ' << road.second << '\n';
}
