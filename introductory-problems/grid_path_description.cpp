#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 7;
const vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string path;
int answer = 0;
vector<vector<int>> grid(N, vector<int>(N, 0));

pair<int, int> get_direction(int i) {
  switch (path[i]) {
  case 'R':
    return moves[0];
  case 'L':
    return moves[1];
  case 'D':
    return moves[2];
    break;
  case 'U':
    return moves[3];
  default:
    return {0, 0};
  }
}

void solve(int row, int col, int i) {
  if (row == N - 1 && col == 0) {
    if (i == 48)
      answer++;
    return;
  }

  if (i == 48)
    return;

  bool up = (row - 1 < 0) || grid[row - 1][col];
  bool down = (row + 1 >= 7) || grid[row + 1][col];
  bool left = (col - 1 < 0) || grid[row][col - 1];
  bool right = (col + 1 >= 7) || grid[row][col + 1];

  if (up && down && !left && !right)
    return;

  if (left && right && !up && !down)
    return;

  pair<int, int> dir = get_direction(i);
  if (dir.first != 0 || dir.second != 0) {
    int r = row + dir.first;
    int c = col + dir.second;
    if (0 <= min(r, c) && max(r, c) < N && !grid[r][c]) {
      grid[r][c] = 1;
      solve(r, c, i + 1);
      grid[r][c] = 0;
    }
  } else {
    for (auto m : moves) {
      int r = row + m.first;
      int c = col + m.second;
      if (0 <= min(r, c) && max(r, c) < N && !grid[r][c]) {
        grid[r][c] = 1;
        solve(r, c, i + 1);
        grid[r][c] = 0;
      }
    }
  }
}

int main() {
  cin >> path;
  grid[0][0] = 1;
  solve(0, 0, 0);
  cout << answer << '\n';
  return 0;
}
