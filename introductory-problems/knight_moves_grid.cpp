#include <iostream>
using namespace std;

typedef vector<vector<int>> two_d;

void moves(two_d &grid) {
  vector<pair<int, int>> queue;
  queue.push_back({0, 0});
  for (int q = 0; q < (int)queue.size(); q++) {
    int i = queue[q].first;
    int j = queue[q].second;
    int initial = grid[i][j];
    int x, y;
    vector<pair<int, int>> possible_moves;
    if (i + 2 < (int)grid.size()) {
      y = i + 2;
      if (j + 1 < (int)grid.size() && grid[y][j + 1] == 0) {
        x = j + 1;
        possible_moves.push_back({y, x});
      }
      if (j - 1 >= 0 && grid[y][j - 1] == 0) {
        x = j - 1;
        possible_moves.push_back({y, x});
      }
    }
    if (i - 2 >= 0) {
      y = i - 2;
      if (j + 1 < (int)grid.size() && grid[y][j + 1] == 0) {
        x = j + 1;
        possible_moves.push_back({y, x});
      }
      if (j - 1 >= 0 && grid[y][j - 1] == 0) {
        x = j - 1;
        possible_moves.push_back({y, x});
      }
    }
    if (i + 1 < (int)grid.size()) {
      y = i + 1;
      if (j + 2 < (int)grid.size() && grid[y][j + 2] == 0) {
        x = j + 2;
        possible_moves.push_back({y, x});
      }
      if (j - 2 >= 0 && grid[y][j - 2] == 0) {
        x = j - 2;
        possible_moves.push_back({y, x});
      }
    }
    if (i - 1 >= 0) {
      y = i - 1;
      if (j + 2 < (int)grid.size() && grid[y][j + 2] == 0) {
        x = j + 2;
        possible_moves.push_back({y, x});
      }
      if (j - 2 >= 0 && grid[y][j - 2] == 0) {
        x = j - 2;
        possible_moves.push_back({y, x});
      }
    }
    for (auto move : possible_moves) {
      y = move.first;
      x = move.second;
      if (x == 0 && y == 0)
        continue;
      grid[y][x] = initial + 1;
      queue.push_back({y, x});
    }
  }
}

int main() {
  int n;
  cin >> n;
  two_d grid(n, vector<int>(n, 0));
  moves(grid);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << '\n';
  }
}
