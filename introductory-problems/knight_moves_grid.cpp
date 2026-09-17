#include <iostream>
using namespace std;

typedef vector<vector<int>> two_d;
vector<pair<int, int>> moves = {{1, 2},  {2, 1},  {-1, 2},  {2, -1},
                                {1, -2}, {-2, 1}, {-2, -1}, {-1, -2}};

void solve(two_d &grid) {
  vector<pair<int, int>> queue;
  queue.push_back({0, 0});
  for (int q = 0; q < (int)queue.size(); q++) {
    int i = queue[q].first;
    int j = queue[q].second;
    int initial = grid[i][j];
    int x, y;
    for (auto move : moves) {
      y = i + move.first;
      x = j + move.second;
      if (x == 0 && y == 0)
        continue;
      if (min(x, y) >= 0 && max(x, y) < (int)grid.size() && grid[y][x] == 0) {
        grid[y][x] = initial + 1;
        queue.push_back({y, x});
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  two_d grid(n, vector<int>(n, 0));
  solve(grid);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << '\n';
  }
}
