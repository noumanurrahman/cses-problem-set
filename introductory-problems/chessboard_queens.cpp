#include <iostream>
#include <vector>
using namespace std;

int solutions = 0;

void place(int row, vector<string> grid) {
  if (row == 8) {
    solutions++;
    return;
  }
  for (int col = 0; col < 8; col++) {
    if (grid[row][col] == '.') {
      bool attacked = false;
      for (int r = 0; r < row; r++) {
        if (grid[r][col] == 'Q') {
          attacked = true;
          break;
        }
      }
      for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; c--, r--) {
        if (grid[r][c] == 'Q') {
          attacked = true;
          break;
        }
      }
      for (int r = row - 1, c = col + 1; r >= 0 && c < 8; c++, r--) {
        if (grid[r][c] == 'Q') {
          attacked = true;
          break;
        }
      }
      if (!attacked) {
        grid[row][col] = 'Q';
        place(row + 1, grid);
        grid[row][col] = '.';
      }
    }
  }
}

int main() {
  vector<string> grid(8);
  for (int i = 0; i < 8; i++) {
    cin >> grid[i];
  }
  place(0, grid);
  cout << solutions << '\n';
}
