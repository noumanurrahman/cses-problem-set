#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  vector<int> students(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (students[i] != 0)
      continue;
    queue<int> q;
    q.push(i);
    students[i] = 1;
    while (!q.empty()) {
      int s = q.front();
      q.pop();
      for (const int x : graph[s]) {
        if (students[x] != 0 && students[s] == students[x]) {
          cout << "IMPOSSIBLE\n";
          return 0;
        }
        if (students[x] != 0)
          continue;
        students[x] = students[s] == 1 ? 2 : 1;
        q.push(x);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << students[i];
    if (i != n)
      cout << ' ';
    else
      cout << '\n';
  }
  return 0;
}
