#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  vector<string> grid(x);
  for (int i = 0; i < x; i++)
    cin >> grid[i];
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      set<char> forbidden;
      if (i != 0)
        forbidden.insert(grid[i - 1][j]);
      if (j != 0)
        forbidden.insert(grid[i][j - 1]);
      forbidden.insert(grid[i][j]);
      for (char c = 'A'; c <= 'D'; c++) {
        if (forbidden.count(c) == 0) {
          grid[i][j] = c;
          break;
        }
      }
    }
    cout << grid[i] << '\n';
  }
}
